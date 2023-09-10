#pragma once
#include<iostream>
#include<map>
#include<vector>

#include"Vector2D.h"
#include"Renderer2D.h"




class Entity
{
private:

	Vector2D Position;
	Vector2D Velocity;

	SDL_Texture* EntityTexture;

	SDL_Rect SrcRect;
	SDL_Rect DestRect;

public:

	Entity(SDL_Renderer*& Renderer, const char* EntityImage, float x = 500, float y = 500, int SpriteWidth = 64, int SpriteHeight = 64) : 

		EntityTexture(Renderer2D::CreateTextureFromImage(Renderer, EntityImage)), 
		Position({ x, y }), 
		Velocity({ 0, 0 }) 
		
	{
		SrcRect = { 0, 0, SpriteWidth, SpriteHeight };
		DestRect = { static_cast<int>(Position.x), static_cast<int>(Position.y),  SpriteWidth, SpriteHeight };
	}

	void RenderEntity(SDL_Renderer* Renderer);

};

