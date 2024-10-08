#include "MapScreen.h"



MapScreen::MapScreen(SDL_Renderer* renderer, Hero* hero, int* items)
{
	this->renderer = renderer;
	this->hero = hero;
	this->items = items;

	//loop through map using nested loop and clear all values out to be zero(walls)
	for (int x = 0; x <= 9; x++)
	{
		for (int y = 0; y <= 9; y++)
		{
			map[x][y] = 0;
		}

	}
	//manual room building
	map[1][1] = 1;
	map[2][1] = 1;
	map[3][1] = 1;
	map[1][2] = 1;
	/*map[2][2] = 1;
	map[3][2] = 1;*/

	//Open map text file
	fstream mapFile("assets/map.txt");
	if (mapFile.is_open())
	{
		for (int y = 0; y <= 9; y++)
		{
			for (int x = 0; x <= 9; x++)
			{
				//read in a single character from where we are up to in the file
				char grid;
				mapFile >> grid;
				if (grid == '0')
				{
					map[x][y] = 0; //wall
				}
				else
				{
					map[x][y] = 1;//land

					//TODO was it a hero, glob, chest or mimic???
					if (grid == 'h')
					{
						heroObj.type = 1;
						heroObj.x = x;
						heroObj.y = y;
					}
					else if (grid == 'd')
					{
						door.type = 2;
						door.x = x;
						door.y = y;
					}
					else if (grid == 'c')
					{
						MapObject chest;
						chest.type = 5;
						chest.x = x;
						chest.y = y;

						mapObjects.push_back(chest);
					}
					else if (grid == 'g')
					{
						MapObject glob;
						glob.type = 3;
						glob.x = x;
						glob.y = y;

						mapObjects.push_back(glob);
					}
					else if (grid == 'm')
					{
						MapObject mimic;
						mimic.type = 4;
						mimic.x = x;
						mimic.y = y;

						mapObjects.push_back(mimic);
					}
				}
			}
		}
	}
	//close file
	mapFile.close();

	//LOAD UP TILE TEXTURES
	heroTexture = IMG_LoadTexture(renderer, "assets/girlTile.png");
	doorTexture = IMG_LoadTexture(renderer, "assets/doorTile.png");
	globTexture = IMG_LoadTexture(renderer, "assets/globTile.png");
	chestTexture = IMG_LoadTexture(renderer, "assets/chestTile.png");
}


MapScreen::~MapScreen()
{
	//CLEANUP TEXTURE MEMORY
	SDL_DestroyTexture(heroTexture);
	SDL_DestroyTexture(doorTexture);
	SDL_DestroyTexture(globTexture);
	SDL_DestroyTexture(chestTexture);
}

void MapScreen::draw() {
	//MAP DRAWING
	//tile representing size of 1 grid thing from map
	SDL_Rect tileRect = { 0,0,32,32 };
	//loop through and draw each grid value from map array
	for (int x = 0; x <= 9; x++)
	{
		for (int y = 0; y <= 9; y++)
		{
			//IF is ground, set draw colour to ground colour
			//ELSE set to wall colour
			if (map[x][y] == 1)
			{
				//ground
				SDL_SetRenderDrawColor(renderer, 136, 60, 100, 255);
			}
			else
			{
				//walls
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			}
			//MOVE rectangle to grid position with regards to tile width/height
			tileRect.x = x * tileRect.w;
			tileRect.y = y * tileRect.h;
			//draw rectangle to screen using current draw colour
			SDL_RenderFillRect(renderer, &tileRect);
		}
	}

	//DRAW MAP OBJECTS
	//draw hero
	tileRect.x = heroObj.x * tileRect.w; //e.g hero x = 4, y = 6. tile w = 32 h = 32
	tileRect.y = heroObj.y * tileRect.h;
	SDL_RenderCopy(renderer, heroTexture, NULL, &tileRect);
	//draw door
	tileRect.x = door.x * tileRect.w;
	tileRect.y = door.y * tileRect.h;
	SDL_RenderCopy(renderer, doorTexture, NULL, &tileRect);
	//DRAW MAP OBJECTS IN LIST
	//loop through list and draw each object
	for (MapObject mo : mapObjects)
	{
		//NOTE: mo is a mapObject copy from mapObjects and is not a direct reference to the mapObject in the list
		if (mo.active)
		{
			tileRect.x = mo.x * tileRect.w;
			tileRect.y = mo.y * tileRect.h;
			if (mo.type == 3)//glob
			{
				SDL_RenderCopy(renderer, globTexture, NULL, &tileRect);
			}
			else//mimic or chest
			{
				SDL_RenderCopy(renderer, chestTexture, NULL, &tileRect);
			}
		}
	}

}