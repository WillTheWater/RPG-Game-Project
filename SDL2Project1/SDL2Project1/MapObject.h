#pragma once
class MapObject
{
public:

	// play = 1, door = 2, glob = 3, mimic = 4, chest = 5
	int type;
	int i, j;
	bool active = true;
};

