
#include <SDL.h>
#include <SDL_image.h>
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

	SDL_Window* window = SDL_CreateWindow("RPG GAME!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 960, SDL_WINDOW_SHOWN);
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
	//Fixing aspec ratio
	SDL_RenderSetLogicalSize(renderer, 320, 240);
	// Loading an image
	SDL_Texture* testImage = IMG_LoadTexture(renderer, "assets/girlIdle.png");
	if (testImage == NULL) { std::cout << "image failed to load\n"; }





	bool keepLooping = true;
	SDL_Event event;
	//Game Loop
	while (keepLooping)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				keepLooping = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);//RGB (e.g R = 0-255)
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
		
		SDL_Rect srcRect;
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 107;
		srcRect.h = 137;

		SDL_Rect destRect;
		destRect.x = 70;
		destRect.y = 20;
		destRect.w = 107;
		destRect.h = 137;
		SDL_RenderCopy(renderer, testImage, &srcRect, &destRect);
		
		//swaps drawing buffer
		SDL_RenderPresent(renderer);


	}
	//CLEANUP
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
