#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "benchmark_common.h"

static int SeedForRepeat(int repeat)
{
	static const int seeds[] = { 1234, 4321, 9999 };
	return seeds[repeat % 3];
}

int main(int argc, char** argv)
{
	if (argc != 5)
	{
		std::cerr << "uso: benchmark_modificado <variante> <cenario> <passos> <repeticoes>\n";
		return 2;
	}

	const std::string variant = argv[1];
	const std::string scenario = argv[2];
	const int steps = std::stoi(argv[3]);
	const int repetitions = std::stoi(argv[4]);
	if ((variant != "modificado_neutro" && variant != "modificado_litologico")
		|| !IsKnownScenario(scenario) || steps <= 0 || repetitions <= 0
		|| (scenario == "rio_real" && !HasRealRiverData()))
		return 2;

	WriteCsvHeader(std::cout);
	for (int repeat = 0; repeat < repetitions; repeat++)
	{
		const int seed = SeedForRepeat(repeat);
		const ScalarField2D terrain = BuildTerrain(scenario);
		const ScalarField2D mobility = variant == "modificado_litologico"
			? BuildLithology(scenario, terrain)
			: BuildUniformLithology(terrain);
		MeanderSimulation simulation(seed, terrain, mobility);
		simulation.AddChannel(Channel(InitialPoints(scenario), 50.0));
		const std::vector<Vector2> initialPoints = simulation.Channels().at(0).Points();
		const std::vector<Vector2> referencePoints = LoadRealReferenceCenterline();

		const auto begin = std::chrono::steady_clock::now();
		RunScenarioSteps(simulation, scenario, steps);
		const auto end = std::chrono::steady_clock::now();
		const long long elapsedNs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

		if (simulation.Channels().empty())
			return 3;
		if (simulation.Channels().at(0).Size() < 4)
			return 4;
		Channel finalChannel = simulation.Channels().at(0);
		WriteCsvRow(std::cout, variant, scenario, steps, seed, repeat,
			MeasureChannel(finalChannel, initialPoints, referencePoints, elapsedNs, steps));
	}
	return 0;
}
