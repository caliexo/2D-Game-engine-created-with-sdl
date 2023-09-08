#pragma once
#include<iostream>
#include<SDL.h>
#include<chrono>
#include <thread>

/*
should be able to :
-limit fps
-calc session time
-calc pause time
-calc afk time
*/

enum FpsCaps
{
	Cap1 = 30,
	Cap2 = 60,
	Cap3 = 144,
	Cap4 = 165,
	Cap5 = 240,
};

class Timer
{
private:

	bool IsRunning;
	bool IsPaused;

	float DeltaTime;
	std::chrono::high_resolution_clock::time_point StartTime;
	std::chrono::high_resolution_clock::time_point Now();
	std::chrono::high_resolution_clock::time_point PrevTime;

	int FrameCount;
	float FPS;
	FpsCaps FpsCap;
	
public:

	std::chrono::duration<float> Sleep;

	Timer() : 
		IsRunning(false),
		IsPaused(false), 
		DeltaTime(0.0f),
		FPS(0.0f), 
		FpsCap(FpsCaps::Cap1),
		FrameCount(0)
	{}

	void StartSession();
	void FinishSession();

	void PauseSession();
	void Resume();
};

