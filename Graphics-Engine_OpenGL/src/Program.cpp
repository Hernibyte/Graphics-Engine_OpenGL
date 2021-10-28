#include "Program.h"

Program::Program() {
	
}

Program::Program(int width, int height, const char* tittle) {
	Window::window->Width(width);
	Window::window->Height(height);
	Window::window->Tittle(tittle);
}

Program::~Program() {
	Window::window->Destroy();
}

void Program::Run() {
	Core_Awake();
	Awake();

	Core_Start();
	Start();

	while (Window::window->IsWindowShouldClose()) {
		Core_LateUpdate();
		LateUpdate();

		Core_Update();
		Update();

		Core_FixedUpdate();
		FixedUpdate();

		Window::window->Refresh();
	}

	Core_Sleep();
	Sleep();
}

void Program::Core_Awake() {

}

void Program::Core_Start() {

}

void Program::Core_LateUpdate() {

}

void Program::Core_Update() {

}

void Program::Core_FixedUpdate() {

}

void Program::Core_Sleep() {

}