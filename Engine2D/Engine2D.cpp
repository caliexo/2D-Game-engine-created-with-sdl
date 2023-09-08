/*
*cpp file for testings
*/

#include <iostream>
#include<SDL.h>


#include"Timer.h"
#include"Renderer2D.h"
#include"Entity.h"

int main(int argc, char* argv[])
{
    Renderer2D* Renderer = new Renderer2D{1920, 1080 };
	Timer time;
	Entity* Champ = new Entity{ Renderer->Renderer, "bbb.jpg", 500, 500 };

    bool quit = false;
    SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		SDL_RenderClear(Renderer->Renderer);
		time.StartSession();
		
		Champ->RenderEntity(Renderer->Renderer);

		SDL_RenderPresent(Renderer->Renderer);
		time.FinishSession();
	}

    return 0;
}
