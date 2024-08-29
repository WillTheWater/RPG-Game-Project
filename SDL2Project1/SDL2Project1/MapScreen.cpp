#include "MapScreen.h"

MapScreen::MapScreen(SDL_Renderer* renderer, Player* player, int* items)
{
	this->renderer = renderer;
	this->player = player;
	this->items = items;

	// Loop through map to zero out map.
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			map[i][j] = 0;
		}
	}
	// Loading txt file
	std::fstream mapfile("assets/map.txt");
	if (mapfile.is_open())
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				char grid;
				mapfile >> grid;
				if (grid == '0') { map[j][i] = 0; } // Wall
				else { map[j][i] = 1; } // Ground
			}
		}
	}
	mapfile.close();
}

MapScreen::~MapScreen()
{
}

void MapScreen::draw()
{
	// Map cell size
	SDL_Rect tileRect = { 0, 0, 32, 32 };
	// Loop to draw from map array
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (map[i][j] == 1)
			{
				SDL_SetRenderDrawColor(renderer, 136, 60, 100, 255); //Ground
			}
			else{ SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); } // Walls
			// Placing rect to grid.
			tileRect.x = i * tileRect.w;
			tileRect.y = j * tileRect.h;
			SDL_RenderFillRect(renderer, &tileRect);
		}

	}
}
