
#include <SDL.h>
#include <stdio.h>
#include<iostream>


int main(int argc, char* args[])
{
	//Initialise SDL2
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		//if init not return 0, then initialisation failed
		std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
		system("pause");
		return 1;

	}

	SDL_Window* window = SDL_CreateWindow("RPG GAME!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 240, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "SDL window Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		system("pause");
		return 1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << "SDL renderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		system("pause");
		return 1;
	}

	bool keepLooping = true;
	//Game Loop
	while (keepLooping)
	{
		SDL_SetRenderDrawColor(renderer, 21, 209, 249, 255);//RGB (e.g R = 0-255)
		//clear entire screen with current draw colour
		SDL_RenderClear(renderer);

		SDL_Rect rect;
		rect.x = 10;
		rect.y = 10;
		rect.w = 50;
		rect.h = 50;
		SDL_SetRenderDrawColor(renderer, 34, 76, 22, 255);
		//draws filled in rectangle to window using rectangles data
		SDL_RenderFillRect(renderer, &rect);

		//swaps drawing buffer
		SDL_RenderPresent(renderer);

		//ticks are milliseconds since the start of SDL init
		if (SDL_GetTicks() > 5000)//1000ms = 1second
		{
			keepLooping = false;
		}
	}
	//CLEANUP
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	//lets user interact by pressing anykey
	system("pause");
	return 0;

	return 0;
}
