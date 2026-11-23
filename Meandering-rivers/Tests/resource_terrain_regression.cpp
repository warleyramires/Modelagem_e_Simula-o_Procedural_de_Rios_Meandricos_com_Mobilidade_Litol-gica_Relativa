#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "meanders.h"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

static ScalarField2D LoadHeightField(const std::string& filename)
{
	int width = 0, height = 0, channels = 0;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height,
		&channels, 1);
	if (data == nullptr)
		return ScalarField2D();

	ScalarField2D terrain(
		width,
		height,
		Box2D(Vector2(0.0), 20000.0),
		0.0);
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			terrain.Set(i, j,
				double(data[j * width + i]) / 255.0 * 2500.0);
	stbi_image_free(data);
	return terrain;
}

static ScalarField2D BuildLithology(const ScalarField2D& terrain)
{
	ScalarField2D field(terrain.SizeX(), terrain.SizeY(), terrain.GetBox(), 1.0);
	for (int i = 0; i < field.SizeX(); i++)
	{
		const double value = i < field.SizeX() / 2 ? 0.5 : 1.5;
		for (int j = 0; j < field.SizeY(); j++)
			field.Set(i, j, value);
	}
	return field;
}

int main(int argc, char** argv)
{
	const std::string filename = argc > 1
		? argv[1]
		: "Resources/hf.png";
	const ScalarField2D terrain = LoadHeightField(filename);
	if (terrain.SizeX() < 2 || terrain.SizeY() < 2)
	{
		std::cerr << "could not load heightfield: " << filename << "\n";
		return 1;
	}

	const ScalarField2D lithology = BuildLithology(terrain);
	const std::vector<Vector2> points =
	{
		Vector2(-7500, 0), Vector2(-1750, 0), Vector2(-1000, 0),
		Vector2(0, 0), Vector2(1000, 0), Vector2(1500, 0),
		Vector2(7500, 0)
	};
	MeanderSimulation simulation(1234, terrain, lithology);
	simulation.AddChannel(Channel(points, 50.0));
	simulation.Step(50);

	for (const Channel& channel : simulation.Channels())
		for (int i = 0; i < channel.Size(); i++)
			if (!Math::IsNumber(channel.Point(i).x)
				|| !Math::IsNumber(channel.Point(i).y)
				|| !Math::IsNumber(channel.MigrationRate(i)))
			{
				std::cerr << "resource terrain produced invalid values\n";
				return 1;
			}

	std::cout << "resource terrain regression passed: "
		<< terrain.SizeX() << "x" << terrain.SizeY() << "\n";
	return 0;
}
