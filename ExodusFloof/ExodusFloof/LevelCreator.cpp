#include "LevelCreator.h"
#include "Floof.h"

#include <cmath>
#include <ctime>
LevelCreator::LevelCreator(size_t tilesX, size_t tilesY)
{
	internalCreateLevel(tilesX, tilesY);
}

std::vector<Floof*>::iterator LevelCreator::iterBegin()
{
	return floofs.begin();
}
std::vector<Floof*>::iterator LevelCreator::iterEnd()	
{
	return floofs.end();
}

void LevelCreator::internalCreateLevel(size_t tilesX, size_t tilesY)
{
	std::srand(std::time(NULL));

	int floorH = std::rand() % 3 + 1;
	int roofH = std::rand() % 3 + 1;

	for (size_t i = 0; i < tilesX; ++i)
	{
		for (size_t floor = 0; floor < floorH; floor++)
		{
			floofs.push_back(new Floof(i * 64 + 32, 64 * tilesY - floor * 64 + 32));
		}

		for (size_t roof = 0; roof < roofH; roof++)
		{
			floofs.push_back(new Floof(i * 64 + 32, roof * 64 + 32));
			
		}

		int oldFloorH = floorH;
		int oldRoofH = roofH;

		floorH = 1;//oldFloorH + std::rand() % 3 - 1; 
		roofH = oldRoofH + std::rand() % 3 - 1;

		if (floorH < 1)
			floorH = 1;
		else if (floorH > 3)
			floorH = 3;

		if (roofH < 1)
			roofH = 1;
		else if (roofH > 3)
			roofH = 3;
	}
}