#ifndef SCRIPT_H
#define SCRIPT_H

class GameObject;
struct Transform;
struct InputSystem;
#include "MyMath/My.h"
#include "Time.h"

class Script {
public:
	GameObject* gameObject = nullptr;
	Transform* transform = nullptr;
	InputSystem* Input = nullptr;

	virtual void Awake() {}
	virtual void Start() {}
	virtual void LateUpdate() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void OnCollisionStay() {}

	virtual ~Script() {}
};

#endif // !SCRIPT_H
