#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// A baseline does not expose its channels publicly. This benchmark-only view
// observes the result without changing the simulation algorithm.
#define private public
#include "meanders.h"
#undef private

#include "benchmark_common.h"

static int SeedForRepeat(int repeat)
{
	static const int seeds[] = { 1234, 4321, 9999 };
	return seeds[repeat % 3];
}

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "uso: benchmark_original <cenario> <repeticoes>\n";
		return 2;
	}

	const std::string scenario = argv[1];
	const int repetitions = std::stoi(argv[2]);
	const int steps = ScenarioSteps(scenario);
	if (steps == 0 || repetitions <= 0)
		return 2;

	WriteCsvHeader(std::cout);
	for (int repeat = 0; repeat < repetitions; repeat++)
	{
		const int seed = SeedForRepeat(repeat);
		const ScalarField2D terrain = BuildTerrain(scenario);
		MeanderSimulation simulation(seed, terrain);
		simulation.AddChannel(Channel(InitialPoints(scenario), 50.0));
		const std::vector<Vector2> initialPoints = simulation.channels.at(0).Points();

		const auto begin = std::chrono::steady_clock::now();
		RunScenarioSteps(simulation, scenario, steps);
		const auto end = std::chrono::steady_clock::now();
		const long long elapsedNs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

		if (simulation.channels.empty())
			return 3;
		Channel finalChannel = simulation.channels.at(0);
		WriteCsvRow(std::cout, "original", scenario, seed, repeat,
			MeasureChannel(finalChannel, initialPoints, elapsedNs, steps));
	}
	return 0;
}
