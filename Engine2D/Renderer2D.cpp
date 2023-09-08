#include "Renderer2D.h"

/*
renderer and window init func, will return true if success else false

input:
-Screen width
-screen height
-window name
-window flag
-renderer index

Using: 
-Window
-Renderer
*/
bool Renderer2D::Init(int ScreenWidth, int ScreenHeight, const char* WindowName, SDL_WindowFlags WindowFlag, int RendererIndex)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    Window = SDL_CreateWindow(WindowName,
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        ScreenWidth,
        ScreenHeight,
        WindowFlag);

    if (!Window) 
    {
        std::cerr << "SDL window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    Renderer = SDL_CreateRenderer(Window, RendererIndex, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);

    return true;
}


/*
this function is like a main render function, it will gather all render functions to here

render functions: 
-Entity Renderer
-Map Renderer
-

output : None
*/
void Renderer2D::Render()
{
}

SDL_Texture* Renderer2D::CreateTextureFromImage(SDL_Renderer* Renderer, const char* imagepath)
{
    SDL_Surface* surface = IMG_Load(imagepath);
    if (!surface) 
    {
        SDL_Log("Failed to load image: %s", IMG_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, surface);

    SDL_FreeSurface(surface);

    return texture;
}

Renderer2D::~Renderer2D()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
}
