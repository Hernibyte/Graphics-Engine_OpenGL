#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time {
public:
	static void CalculateFPS();
	static void Reset();
	static void Start();
	static void Tick();

	static std::chrono::time_point<std::chrono::steady_clock> start;
	static std::chrono::duration<float> duration;

	static float DeltaTime;
	static float TimeScale;
	static float FixedTimeScale;
	static float FPS;
	static float ElapsedTime;
};

#endif // !TIME_H
