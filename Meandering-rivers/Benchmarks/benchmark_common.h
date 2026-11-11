#pragma once

#include "meanders.h"

#include <cmath>
#include <iomanip>
#include <limits>
#include <ostream>
#include <string>
#include <vector>

struct BenchmarkMetrics
{
	long long totalTimeNs = 0;
	double timePerStepNs = 0.0;
	double finalSinuosity = 0.0;
	double finalCurvilinearLength = 0.0;
	double finalLinearLength = 0.0;
	double maxLateralDisplacement = 0.0;
	int finalPointCount = 0;
	int invalidValues = 0;
};

inline int ScenarioSteps(const std::string& scenario)
{
	if (scenario == "plano_500" || scenario == "litologia_500")
		return 500;
	if (scenario == "terreno_1200")
		return 1200;
	if (scenario == "avulsao_750")
		return 750;
	return 0;
}

inline std::vector<Vector2> InitialPoints(const std::string& scenario)
{
	if (scenario == "terreno_1200")
	{
		return
		{
			Vector2(0, -8500), Vector2(0, -1750), Vector2(0, -1000),
			Vector2(0, 0), Vector2(0, 1000), Vector2(0, 1500), Vector2(0, 8500)
		};
	}
	return
	{
		Vector2(-7500, 0), Vector2(-1750, 0), Vector2(-1000, 0),
		Vector2(0, 0), Vector2(1000, 0), Vector2(1500, 0), Vector2(7500, 0)
	};
}

inline ScalarField2D BuildTerrain(const std::string& scenario)
{
	ScalarField2D terrain(256, 256, Box2D(Vector2(0.0), 10000.0), 0.0);
	if (scenario != "terreno_1200")
		return terrain;

	const Box2D box = terrain.GetBox();
	for (int i = 0; i < terrain.SizeX(); i++)
	{
		const double x = box[0].x + (box[1].x - box[0].x) * double(i) / 255.0;
		for (int j = 0; j < terrain.SizeY(); j++)
		{
			const double y = box[0].y + (box[1].y - box[0].y) * double(j) / 255.0;
			const double height = 400.0
				+ 250.0 * std::sin(x / 1800.0) * std::cos(y / 2200.0);
			terrain.Set(i, j, height);
		}
	}
	return terrain;
}

inline ScalarField2D BuildUniformLithology(const ScalarField2D& terrain)
{
	return ScalarField2D(256, 256, terrain.GetBox(), 1.0);
}

inline ScalarField2D BuildHeterogeneousLithology(const ScalarField2D& terrain)
{
	ScalarField2D field(256, 256, terrain.GetBox(), 1.0);
	const Box2D box = field.GetBox();
	for (int i = 0; i < field.SizeX(); i++)
	{
		const double x = box[0].x + (box[1].x - box[0].x) * double(i) / 255.0;
		const double value = x < -3000.0 ? 0.25 : (x > 3000.0 ? 1.75 : 1.0);
		for (int j = 0; j < field.SizeY(); j++)
			field.Set(i, j, value);
	}
	return field;
}

template<typename Simulation>
inline void RunScenarioSteps(Simulation& simulation, const std::string& scenario, int steps)
{
	if (scenario == "avulsao_750")
	{
		for (int i = 0; i < 700; i++)
			simulation.Step();
		simulation.TriggerAvulsion();
		simulation.TriggerAvulsion();
		for (int i = 700; i < steps; i++)
			simulation.Step();
		return;
	}
	simulation.Step(steps);
}

inline BenchmarkMetrics MeasureChannel(Channel& channel,
	const std::vector<Vector2>& initialPoints,
	long long elapsedNs,
	int steps)
{
	BenchmarkMetrics metrics;
	metrics.totalTimeNs = elapsedNs;
	metrics.timePerStepNs = double(elapsedNs) / double(steps);
	metrics.finalSinuosity = channel.Sinuosity();
	metrics.finalCurvilinearLength = channel.CurvilinearLength();
	metrics.finalLinearLength = channel.Length();
	metrics.finalPointCount = channel.Size();
	const int count = Math::Min(channel.Size(), int(initialPoints.size()));
	for (int i = 0; i < count; i++)
		metrics.maxLateralDisplacement = Math::Max(
			metrics.maxLateralDisplacement,
			Magnitude(channel.Point(i) - initialPoints[i]));
	for (int i = 0; i < channel.Size(); i++)
	{
		if (!Math::IsNumber(channel.Point(i).x)
			|| !Math::IsNumber(channel.Point(i).y)
			|| !Math::IsNumber(channel.MigrationRate(i)))
			metrics.invalidValues++;
	}
	return metrics;
}

inline void WriteCsvHeader(std::ostream& output)
{
	output << "variant,scenario,seed,repeat,total_time_ns,time_per_step_ns,"
		<< "final_sinuosity,final_curvilinear_length,final_linear_length,"
		<< "max_lateral_displacement,final_point_count,invalid_values\n";
}

inline void WriteCsvRow(std::ostream& output,
	const std::string& variant,
	const std::string& scenario,
	int seed,
	int repeat,
	const BenchmarkMetrics& metrics)
{
	output << std::setprecision(17)
		<< variant << ',' << scenario << ',' << seed << ',' << repeat << ','
		<< metrics.totalTimeNs << ',' << metrics.timePerStepNs << ','
		<< metrics.finalSinuosity << ',' << metrics.finalCurvilinearLength << ','
		<< metrics.finalLinearLength << ',' << metrics.maxLateralDisplacement << ','
		<< metrics.finalPointCount << ',' << metrics.invalidValues << '\n';
}
