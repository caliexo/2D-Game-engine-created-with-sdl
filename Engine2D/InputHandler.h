#pragma once
#include<iostream>
#include<map>

#include"Vector2D.h"
#include <SDL.h>

class Keyboard
{
private:

public:

	bool IsKeyPressed();
	bool IsKeyReleased();
};

class Mouse
{
private:

	Vector2D MousePosition;

public:

	Vector2D GetMousePosition() { return this->MousePosition; }

	bool IsButtonPressed();
	bool IsButtonReleased();
	bool IsMouseMoving();
};

class Keybinds
{
private:

	std::map<std::string, SDL_Scancode> _Keybinds;

public:

	void ConnectActionToKey(const std::string& NewActionName, SDL_Scancode Key)
	{
		_Keybinds[NewActionName] = Key;
	}
};

class InputHandler
{
private:

	Keyboard Keyboard;
	Mouse Mouse;

public:

	InputHandler();
	~InputHandler();

	void UpdateInputHandler();

	bool QuitRequested();
	void QuitWindow();
};

