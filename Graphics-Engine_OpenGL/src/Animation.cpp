#include "Animation.h"

void Animation::AddFrame(
	float texture_size_x, float texture_size_y,
	float down_left_point_x, float down_left_point_y,
	float width, float height, float durationFrame)
{
	Frame frame;

	frame.uv[0].u = down_left_point_x / texture_size_x;
	frame.uv[0].v = down_left_point_y / texture_size_y;

	frame.uv[1].u = (down_left_point_x + width) / texture_size_x;
	frame.uv[1].v = frame.uv[0].v;

	frame.uv[2].u = (down_left_point_x + width) / texture_size_x;
	frame.uv[2].v = (down_left_point_y + height) / texture_size_y;

	frame.uv[3].u = frame.uv[0].u;
	frame.uv[3].v = (down_left_point_y + height) / texture_size_y;

	frame.duration = durationFrame;

	frames.push_back(frame);

	UpdateKeyFrame();
}

void Animation::AddFrame(
	float texture_size_x, float texture_size_y,
	float down_left_point_x, float down_left_point_y,
	float width, float height)
{
	Frame frame;

	frame.uv[0].u = down_left_point_x / texture_size_x;
	frame.uv[0].v = down_left_point_y / texture_size_y;
	
	frame.uv[1].u = (down_left_point_x + width) / texture_size_x;
	frame.uv[1].v = frame.uv[0].v;
	
	frame.uv[2].u = (down_left_point_x + width) / texture_size_x;
	frame.uv[2].v = (down_left_point_y + height) / texture_size_y;
	
	frame.uv[3].u = frame.uv[0].u;
	frame.uv[3].v = (down_left_point_y + height) / texture_size_y;

	frames.push_back(frame);

	UpdateFrameDuration();
	UpdateKeyFrame();
}

void Animation::UpdateFrame(float timer) {
	if (frames.size() >= 1) {
		float aux = 0;
		for (int i = 0; i < frames.size(); i++) {
			if (timer > aux && timer < frames[i].keyframe)
				currentFrame = i;
			aux += frames[i].duration;
		}
	}
}

void Animation::SetFrameDuration(int frame, float duration) {
	frames[frame].duration = duration;
}

void Animation::UpdateFrameDuration() {
	float timePerFrame = animationTime / frames.size();
	for (auto& g : frames)
		g.duration = timePerFrame;
}

void Animation::UpdateKeyFrame() {
	float lastKeyFrame = 0;
	for (auto& g : frames) {
		lastKeyFrame += g.duration;
		g.keyframe = lastKeyFrame;
	}
}

Frame Animation::GetFrame(int index) {
	return frames[index];
}

Frame Animation::GetCurrentFrame() {
	return frames[currentFrame];
}