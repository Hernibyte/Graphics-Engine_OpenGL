#ifndef WINDOW_H
#define WINDOW_H

#include "GL/glew.h"
#include "glfw3.h"
#include "Export.h"
#include <iostream>

class ENGINE_API Window {
public:
	static Window* window;

	Window();
	Window(Window& other) = delete;
	Window* operator=(const Window&) = delete;

	void Destroy();

	Window* Instance() { 
		if (window == nullptr)
			window = new Window();
		return window;
	}

	void Width(int width);
	int Width();

	void Height(int height);
	int Height();

	void Tittle(const char* tittle);
	const char* Tittle();

	void SetWindowShouldClose(bool state);
	bool IsWindowShouldClose();

	GLFWwindow* glfwWindow();

	void Refresh();
private:
	int width;
	int height;
	const char* tittle;
	GLFWwindow* WinMain;

	void Start();
};

#endif // !WINDOW_H
