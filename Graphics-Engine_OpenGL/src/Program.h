#ifndef PROGRAM_H
#define PROGRAM_H

#include "Window.h"

class ENGINE_API Program {
public:
	Program();
	Program(int width, int height, const char* tittle);
	~Program();

	void Run();

	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void LateUpdate() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Sleep() = 0;
private:
	Window* window;

	void Core_Awake();
	void Core_Start();
	void Core_LateUpdate();
	void Core_Update();
	void Core_FixedUpdate();
	void Core_Sleep();
};

#endif // !PROGRAM_H
