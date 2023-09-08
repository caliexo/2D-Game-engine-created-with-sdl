#include "Entity.h"

void Entity::RenderEntity(SDL_Renderer* Renderer)
{
	SDL_RenderCopy(Renderer, EntityTexture,&SrcRect, &DestRect);
}
