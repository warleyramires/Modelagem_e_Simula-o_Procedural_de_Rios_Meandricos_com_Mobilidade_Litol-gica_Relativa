#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "benchmark_common.h"

static int SeedForRepeat(int repeat)
{
	static const int seeds[] = { 1234, 4321, 9999 };
	return seeds[repeat % 3];
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "uso: benchmark_modificado <variante> <cenario> <repeticoes>\n";
		return 2;
	}

	const std::string variant = argv[1];
	const std::string scenario = argv[2];
	const int repetitions = std::stoi(argv[3]);
	const int steps = ScenarioSteps(scenario);
	if ((variant != "modificado_neutro" && variant != "modificado_litologico")
		|| steps == 0 || repetitions <= 0)
		return 2;

	WriteCsvHeader(std::cout);
	for (int repeat = 0; repeat < repetitions; repeat++)
	{
		const int seed = SeedForRepeat(repeat);
		const ScalarField2D terrain = BuildTerrain(scenario);
		const ScalarField2D mobility = variant == "modificado_litologico"
			? BuildHeterogeneousLithology(terrain)
			: BuildUniformLithology(terrain);
		MeanderSimulation simulation(seed, terrain, mobility);
		simulation.AddChannel(Channel(InitialPoints(scenario), 50.0));
		const std::vector<Vector2> initialPoints = simulation.Channels().at(0).Points();

		const auto begin = std::chrono::steady_clock::now();
		RunScenarioSteps(simulation, scenario, steps);
		const auto end = std::chrono::steady_clock::now();
		const long long elapsedNs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

		if (simulation.Channels().empty())
			return 3;
		Channel finalChannel = simulation.Channels().at(0);
		WriteCsvRow(std::cout, variant, scenario, seed, repeat,
			MeasureChannel(finalChannel, initialPoints, elapsedNs, steps));
	}
	return 0;
}
