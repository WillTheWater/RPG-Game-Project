#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include <fstream>
#include "MapObject.h"
#include <list>

class MapScreen
{
public:
	MapScreen(SDL_Renderer* renderer, Player* player, int* items);
	~MapScreen();

	SDL_Renderer*				renderer;
	int*						items; //Points to items array in main.cpp
	Player*						player;
	// 2D array representing map; wall = 0, ground = 1
	int							map[10][10];
	MapObject player;
	MapObject door;
	std::list<MapObject> mapObjects;
	void						draw();

};

