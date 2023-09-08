#include "Timer.h"

std::chrono::high_resolution_clock::time_point Timer::Now()
{
	return std::chrono::high_resolution_clock::now();
}

void Timer::StartSession()
{
	StartTime = Now();
}

void Timer::FinishSession()
{
	std::chrono::high_resolution_clock::time_point FinishTime = Now();
	std::chrono::duration<float> TSLF = FinishTime - StartTime;
	DeltaTime = TSLF.count();
	
	FrameCount++;
	float ElapsedTime = std::chrono::duration_cast<std::chrono::seconds>(FinishTime - PrevTime).count();

	if (ElapsedTime >= 1.0f)
	{
		FPS = FrameCount / ElapsedTime;
		FrameCount = 0;
		PrevTime = FinishTime;
	}

	if (FPS > 30) {
		float frameTime = 1.0f / 30;
		std::chrono::duration<float> sleepDuration(frameTime * DeltaTime);
		Sleep = sleepDuration;
	}
}

void Timer::PauseSession()
{
	IsRunning = false;
	IsPaused = true;
}

void Timer::Resume()
{
	IsRunning = true;
	IsPaused = false;
}

