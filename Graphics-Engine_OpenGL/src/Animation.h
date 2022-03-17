#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"

class Animation {
public:
	void AddFrame(
		float texture_size_x, float texture_size_y,
		float down_left_point_x, float down_left_point_y,
		float width, float height, float durationFrame);

	void AddFrame(
		float texture_size_x, float texture_size_y,
		float down_left_point_x, float down_left_point_y,
		float width, float height);

	void AnimationTime(float time) { animationTime = time; }
	float AnimationTime() { return animationTime; }

	void UpdateFrame(float timer);

	void SetFrameDuration(int frame, float duration);

	Frame GetFrame(int index);
	Frame GetCurrentFrame();

private:
	void UpdateFrameDuration();
	void UpdateKeyFrame();
	
	int currentFrame = 0;
	std::vector<Frame> frames;
	float animationTime;
};

#endif // !ANIMATION_H
