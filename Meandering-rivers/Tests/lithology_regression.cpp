#include "meanders.h"

#include <cmath>
#include <iostream>
#include <vector>

static std::vector<Vector2> InitialPoints()
{
	return
	{
		Vector2(-7500, 0), Vector2(-1750, 0), Vector2(-1000, 0),
		Vector2(0, 0), Vector2(1000, 0), Vector2(1500, 0), Vector2(7500, 0)
	};
}

static MeanderSimulation MakeSimulation(const ScalarField2D& terrain, const ScalarField2D* lithology)
{
	MeanderSimulation simulation = lithology
		? MeanderSimulation(1234, terrain, *lithology)
		: MeanderSimulation(1234, terrain);
	simulation.AddChannel(Channel(InitialPoints(), 50.0));
	return simulation;
}

static bool SameChannel(const Channel& a, const Channel& b, double epsilon)
{
	if (a.Size() != b.Size())
		return false;
	for (int i = 0; i < a.Size(); i++)
	{
		if (Magnitude(a.Point(i) - b.Point(i)) > epsilon)
			return false;
	}
	return true;
}

static double MaximumDisplacement(const Channel& channel,
	const std::vector<Vector2>& initial)
{
	double maximum = 0.0;
	const int count = Math::Min(channel.Size(), int(initial.size()));
	for (int i = 0; i < count; i++)
		maximum = Math::Max(maximum, Magnitude(channel.Point(i) - initial[i]));
	return maximum;
}

static ScalarField2D LithologyWithValue(const ScalarField2D& terrain, double value)
{
	return ScalarField2D(256, 256, terrain.GetBox(), value);
}

static ScalarField2D SplitLithology(const ScalarField2D& terrain,
	double leftValue, double rightValue)
{
	ScalarField2D field(256, 256, terrain.GetBox(), 1.0);
	const Box2D box = field.GetBox();
	for (int i = 0; i < field.SizeX(); i++)
	{
		const double x = box[0].x
			+ (box[1].x - box[0].x) * double(i) / 255.0;
		const double value = x < 5000.0 ? leftValue : rightValue;
		for (int j = 0; j < field.SizeY(); j++)
			field.Set(i, j, value);
	}
	return field;
}

static bool HasFiniteChannel(const Channel& channel)
{
	for (int i = 0; i < channel.Size(); i++)
		if (!Math::IsNumber(channel.Point(i).x)
			|| !Math::IsNumber(channel.Point(i).y)
			|| !Math::IsNumber(channel.MigrationRate(i)))
			return false;
	return true;
}

int main()
{
	const ScalarField2D terrain(256, 256, Box2D(Vector2(0.0), 10000.0), 0.0);
	const ScalarField2D uniform(256, 256, terrain.GetBox(), 1.0);
	const std::vector<Vector2> initial = InitialPoints();

	MeanderSimulation baseline = MakeSimulation(terrain, nullptr);
	MeanderSimulation neutral = MakeSimulation(terrain, &uniform);
	baseline.Step(50);
	neutral.Step(50);
	if (!SameChannel(baseline.Channels().at(0), neutral.Channels().at(0), 1.0e-9))
	{
		std::cerr << "E=1 regression failed\n";
		return 1;
	}

	ScalarField2D heterogeneous = SplitLithology(terrain, 0.25, 1.75);
	MeanderSimulation modified = MakeSimulation(terrain, &heterogeneous);
	modified.Step(50);
	for (const Channel& channel : modified.Channels())
		if (!HasFiniteChannel(channel))
		{
			std::cerr << "heterogeneous field produced invalid values\n";
			return 1;
		}

	if (SameChannel(baseline.Channels().at(0), modified.Channels().at(0), 1.0e-6))
	{
		std::cerr << "heterogeneous field had no effect\n";
		return 1;
	}

	const ScalarField2D resistantField = SplitLithology(terrain, 0.5, 1.5);
	const ScalarField2D erodibleField = SplitLithology(terrain, 1.5, 0.5);
	MeanderSimulation resistant = MakeSimulation(terrain, &resistantField);
	MeanderSimulation erodible = MakeSimulation(terrain, &erodibleField);
	resistant.Step(50);
	erodible.Step(50);
	const double resistantDisplacement = MaximumDisplacement(
		resistant.Channels().at(0), initial);
	const double erodibleDisplacement = MaximumDisplacement(
		erodible.Channels().at(0), initial);
	if (!(resistantDisplacement < erodibleDisplacement))
	{
		std::cerr << "resistant and erodible materials were not ordered\n";
		return 1;
	}

	const ScalarField2D neutralField = LithologyWithValue(terrain, 1.0);
	MeanderSimulation inflection = MakeSimulation(terrain, &neutralField);
	inflection.Step(50);
	if (!HasFiniteChannel(inflection.Channels().at(0)))
	{
		std::cerr << "inflection sampling produced invalid values\n";
		return 1;
	}

	MeanderSimulation cleared = MakeSimulation(terrain, &uniform);
	cleared.ClearLithologyField();
	MeanderSimulation baselineCleared = MakeSimulation(terrain, nullptr);
	cleared.Step(50);
	baselineCleared.Step(50);
	if (!SameChannel(cleared.Channels().at(0), baselineCleared.Channels().at(0), 1.0e-9))
	{
		std::cerr << "cleared lithology did not restore baseline\n";
		return 1;
	}

	std::cout << "lithology regression passed: e1, ordering, inflection, clear\n";
	return 0;
}
