#include "MapScreen.h"

MapScreen::MapScreen(SDL_Renderer* renderer, Player* player, int* items)
{
	this->renderer = renderer;
	this->player = player;
	this->items = items;

	// Loop through map to zero out map.
	for (int i = 0; i < 10; ++i)
	{
		for (int k = 0; k < 10; ++k)
		{
			map[i][k] = 0;
		}
	}
	map[1][1] = 1;
	map[2][1] = 1;
	map[3][3] = 1;
	map[6][1] = 1;
	map[4][4] = 1;
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
