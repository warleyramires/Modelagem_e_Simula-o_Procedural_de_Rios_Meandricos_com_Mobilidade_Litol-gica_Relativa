#pragma once

#include "meanders.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <limits>
#include <ostream>
#include <sstream>
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
	double referenceCenterlineError = -1.0;
	int finalPointCount = 0;
	int invalidValues = 0;
};

inline bool IsKnownScenario(const std::string& scenario)
{
	return scenario == "plano"
		|| scenario == "litologia_plana"
		|| scenario == "terreno"
		|| scenario == "relevo_litologia"
		|| scenario == "avulsao"
		|| scenario == "rio_real";
}

inline bool HasRealRiverData()
{
	const char* directory = std::getenv("REAL_RIVER_DATA_DIR");
	return directory != nullptr && *directory != '\0';
}

inline std::string RealRiverPath(const std::string& filename)
{
	const char* directory = std::getenv("REAL_RIVER_DATA_DIR");
	if (directory == nullptr || *directory == '\0')
		return std::string();
	return std::string(directory) + "/" + filename;
}

inline ScalarField2D LoadRealPng(const std::string& filename,
	double minimum, double maximum)
{
	int width = 0, height = 0, channels = 0;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height,
		&channels, 1);
	if (data == nullptr || width < 2 || height < 2)
	{
		if (data != nullptr)
			stbi_image_free(data);
		return ScalarField2D();
	}

	ScalarField2D field(width, height, Box2D(Vector2(0.0), 20000.0), 0.0);
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			const double normalized = double(data[j * width + i]) / 255.0;
			field.Set(i, j, minimum + normalized * (maximum - minimum));
		}
	stbi_image_free(data);
	return field;
}

inline std::vector<Vector2> LoadRealCenterline()
{
	std::ifstream input(RealRiverPath("centerline.csv"));
	std::vector<Vector2> points;
	std::string line;
	while (std::getline(input, line))
	{
		if (line.empty() || line[0] == '#')
			continue;
		std::replace(line.begin(), line.end(), ';', ',');
		std::stringstream values(line);
		std::string xText, yText;
		if (!std::getline(values, xText, ',') || !std::getline(values, yText, ','))
			continue;
		try
		{
			points.emplace_back(std::stod(xText), std::stod(yText));
		}
		catch (const std::exception&)
		{
			continue;
		}
	}
	return points;
}

inline std::vector<Vector2> LoadRealReferenceCenterline()
{
	const std::string filename = RealRiverPath("reference_centerline.csv");
	if (filename.empty())
		return std::vector<Vector2>();
	std::ifstream input(filename);
	std::vector<Vector2> points;
	std::string line;
	while (std::getline(input, line))
	{
		if (line.empty() || line[0] == '#')
			continue;
		std::replace(line.begin(), line.end(), ';', ',');
		std::stringstream values(line);
		std::string xText, yText;
		if (!std::getline(values, xText, ',') || !std::getline(values, yText, ','))
			continue;
		try
		{
			points.emplace_back(std::stod(xText), std::stod(yText));
		}
		catch (const std::exception&)
		{
			continue;
		}
	}
	return points;
}

inline std::vector<Vector2> InitialPoints(const std::string& scenario)
{
	if (scenario == "rio_real")
	{
		const std::vector<Vector2> points = LoadRealCenterline();
		if (!points.empty())
			return points;
	}
	if (scenario == "terreno" || scenario == "relevo_litologia")
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
	if (scenario == "rio_real")
		return LoadRealPng(RealRiverPath("terrain.png"), 0.0, 2500.0);

	ScalarField2D terrain(256, 256, Box2D(Vector2(0.0), 10000.0), 0.0);
	if (scenario != "terreno" && scenario != "relevo_litologia")
		return terrain;

	const Box2D box = terrain.GetBox();
	for (int i = 0; i < terrain.SizeX(); i++)
	{
		const double x = box[0].x + (box[1].x - box[0].x) * double(i) / 255.0;
		for (int j = 0; j < terrain.SizeY(); j++)
		{
			const double y = box[0].y + (box[1].y - box[0].y) * double(j) / 255.0;
			const double height = 400.0
				+ 250.0 * std::sin(x / 1800.0) * std::cos(y / 2200.0)
				+ (scenario == "relevo_litologia"
					? 120.0 * std::sin((x + y) / 900.0)
					: 0.0);
			terrain.Set(i, j, height);
		}
	}
	return terrain;
}

inline ScalarField2D BuildUniformLithology(const ScalarField2D& terrain)
{
	if (terrain.SizeX() < 2 || terrain.SizeY() < 2)
		return ScalarField2D();
	return ScalarField2D(terrain.SizeX(), terrain.SizeY(), terrain.GetBox(), 1.0);
}

inline ScalarField2D BuildHeterogeneousLithology(
	const ScalarField2D& terrain,
	const std::string& scenario);

inline ScalarField2D BuildLithology(const std::string& scenario,
	const ScalarField2D& terrain)
{
	if (scenario == "rio_real")
		return LoadRealPng(RealRiverPath("lithology.png"), 0.25, 1.75);
	return BuildHeterogeneousLithology(terrain, scenario);
}

inline ScalarField2D BuildHeterogeneousLithology(
	const ScalarField2D& terrain,
	const std::string& scenario = "")
{
	ScalarField2D field(256, 256, terrain.GetBox(), 1.0);
	const Box2D box = field.GetBox();
	if (scenario == "litologia_plana")
	{
		// In ScalarField2D::GetValueBilinear, index j maps to world X and i to world Y.
		// Varying along j places resistant/neutral/erodible zones transversally across the horizontal channel.
		for (int j = 0; j < field.SizeY(); j++)
		{
			const double x = box[0].x + (box[1].x - box[0].x) * double(j) / 255.0;
			const double value = x < -3000.0 ? 0.25 : (x > 3000.0 ? 1.75 : 1.0);
			for (int i = 0; i < field.SizeX(); i++)
				field.Set(i, j, value);
		}
		return field;
	}
	for (int i = 0; i < field.SizeX(); i++)
	{
		const double coord = box[0].y + (box[1].y - box[0].y) * double(i) / 255.0;
		const double value = coord < -3000.0 ? 0.25 : (coord > 3000.0 ? 1.75 : 1.0);
		for (int j = 0; j < field.SizeY(); j++)
			field.Set(i, j, value);
	}
	return field;
}

template<typename Simulation>
inline void RunScenarioSteps(Simulation& simulation, const std::string& scenario, int steps)
{
	if (scenario == "avulsao")
	{
		const int avulsionStep = Math::Clamp(int(0.7 * steps), 1, steps);
		for (int i = 0; i < avulsionStep; i++)
			simulation.Step();
		simulation.TriggerAvulsion();
		simulation.TriggerAvulsion();
		for (int i = avulsionStep; i < steps; i++)
			simulation.Step();
		return;
	}
	simulation.Step(steps);
}

inline BenchmarkMetrics MeasureChannel(Channel& channel,
	const std::vector<Vector2>& initialPoints,
	const std::vector<Vector2>& referencePoints,
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
	if (referencePoints.size() >= 2 && channel.Size() >= 2)
	{
		double error = 0.0;
		for (int i = 0; i < channel.Size(); i++)
		{
			const double ratio = double(i) / double(channel.Size() - 1);
			const int referenceIndex = Math::Clamp(
				int(ratio * double(referencePoints.size() - 1)),
				0, int(referencePoints.size() - 1));
			error += Magnitude(channel.Point(i) - referencePoints[referenceIndex]);
		}
		metrics.referenceCenterlineError = error / double(channel.Size());
	}
	return metrics;
}

inline void WriteCsvHeader(std::ostream& output)
{
	output << "variant,scenario,steps,seed,repeat,total_time_ns,time_per_step_ns,"
		<< "final_sinuosity,final_curvilinear_length,final_linear_length,"
		<< "max_lateral_displacement,reference_centerline_error,"
		<< "final_point_count,invalid_values\n";
}

inline void WriteCsvRow(std::ostream& output,
	const std::string& variant,
	const std::string& scenario,
	int steps,
	int seed,
	int repeat,
	const BenchmarkMetrics& metrics)
{
	output << std::setprecision(17)
		<< variant << ',' << scenario << ',' << steps << ',' << seed << ',' << repeat << ','
		<< metrics.totalTimeNs << ',' << metrics.timePerStepNs << ','
		<< metrics.finalSinuosity << ',' << metrics.finalCurvilinearLength << ','
		<< metrics.finalLinearLength << ',' << metrics.maxLateralDisplacement << ','
		<< metrics.referenceCenterlineError << ','
		<< metrics.finalPointCount << ',' << metrics.invalidValues << '\n';
}
