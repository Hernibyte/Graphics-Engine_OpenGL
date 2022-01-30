#ifndef ANIMATOR2D_H
#define ANIMATOR2D_H

#include "SpriteRenderer.h"

class Animator2D : public Script {
public:
	void Awake() {
		if (gameObject->HasComponent<SpriteRenderer>())
			sprite = &gameObject->GetComponent<SpriteRenderer>();
		else
			std::cout << "Sprite component not found" << std::endl;
	}

	void Update() {
		timer += Time::DeltaTime;
		if (timer >= animations[currentAnimation].AnimationTime()) timer = 0;
		
		animations[currentAnimation].UpdateFrame(timer);
		UpdateUV();
	}

	void SetCurrentAnimation(int current) {
		currentAnimation = current;
	}

	void AddAnimation(Animation animation) {
		animations.push_back(animation);
	}

	void AddAnimation() {
		animations.push_back(Animation{});
	}

	Animation GetAnimation(int index) {
		return animations[index];
	}
private:
	void UpdateUV() {
		sprite->SetUVPoint1(
			animations[currentAnimation].GetCurrentFrame().uv[2].u,
			animations[currentAnimation].GetCurrentFrame().uv[2].v);
		sprite->SetUVPoint2(
			animations[currentAnimation].GetCurrentFrame().uv[1].u,
			animations[currentAnimation].GetCurrentFrame().uv[1].v);
		sprite->SetUVPoint3(
			animations[currentAnimation].GetCurrentFrame().uv[0].u,
			animations[currentAnimation].GetCurrentFrame().uv[0].v);
		sprite->SetUVPoint4(
			animations[currentAnimation].GetCurrentFrame().uv[3].u,
			animations[currentAnimation].GetCurrentFrame().uv[3].v);
	}

	int currentAnimation = 0;

	float timer;
	SpriteRenderer* sprite;
	std::vector<Animation> animations;
};

#endif // !ANIMATOR2D_H
