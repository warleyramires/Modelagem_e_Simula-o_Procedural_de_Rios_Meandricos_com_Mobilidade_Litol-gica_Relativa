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

int main()
{
	const ScalarField2D terrain(256, 256, Box2D(Vector2(0.0), 10000.0), 0.0);
	const ScalarField2D uniform(256, 256, terrain.GetBox(), 1.0);

	MeanderSimulation baseline = MakeSimulation(terrain, nullptr);
	MeanderSimulation neutral = MakeSimulation(terrain, &uniform);
	baseline.Step(50);
	neutral.Step(50);
	if (!SameChannel(baseline.Channels().at(0), neutral.Channels().at(0), 1.0e-9))
	{
		std::cerr << "E=1 regression failed\n";
		return 1;
	}

	ScalarField2D heterogeneous(256, 256, terrain.GetBox(), 1.0);
	for (int i = 0; i < heterogeneous.SizeX(); i++)
	{
		const double x = heterogeneous.Vertex(i, 0).z;
		for (int j = 0; j < heterogeneous.SizeY(); j++)
			heterogeneous.Set(i, j, x < 0.0 ? 0.25 : 1.75);
	}
	MeanderSimulation modified = MakeSimulation(terrain, &heterogeneous);
	modified.Step(50);
	for (const Channel& channel : modified.Channels())
		for (int i = 0; i < channel.Size(); i++)
			if (!Math::IsNumber(channel.Point(i).x) || !Math::IsNumber(channel.Point(i).y))
			{
				std::cerr << "heterogeneous field produced NaN\n";
				return 1;
			}

	if (SameChannel(baseline.Channels().at(0), modified.Channels().at(0), 1.0e-6))
	{
		std::cerr << "heterogeneous field had no effect\n";
		return 1;
	}

	std::cout << "lithology regression passed\n";
	return 0;
}
