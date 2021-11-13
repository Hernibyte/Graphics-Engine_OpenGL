#ifndef SCRIPT_H
#define SCRIPT_H

class GameObject;
class Transform;

class Script {
public:
	GameObject* gameObject = nullptr;
	Transform* transform = nullptr;

	virtual void Awake() {}
	virtual void Start() {}
	virtual void LateUpdate() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}

	virtual ~Script() {}
};

#endif // !SCRIPT_H
