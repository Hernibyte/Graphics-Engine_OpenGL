#include "Time.h"

std::chrono::time_point<std::chrono::steady_clock> Time::start;
std::chrono::duration<float> Time::duration = std::chrono::duration<float>(0.0f);
float Time::DeltaTime = 0.0f;
float Time::TimeScale = 1.0f;
float Time::FPS = 0.0f;
float Time::ElapsedTime = 0.0f;

void Time::CalculateFPS() {
	Time::FPS = 1.0f / duration.count();
}

void Time::Reset() {
	Start();
}

void Time::Start() {
	start = std::chrono::high_resolution_clock::now();
}

void Time::Tick() {
	duration = std::chrono::high_resolution_clock::now() - start;
	CalculateFPS();
	DeltaTime = duration.count();
	ElapsedTime += duration.count();
}