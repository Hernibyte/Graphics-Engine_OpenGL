#ifndef WINDOW_H
#define WINDOW_H

#include "GL/glew.h"
#include "glfw3.h"
#include <iostream>

class Window {
public:
	static Window* window;

	Window();
	Window(Window& other) = delete;
	Window* operator=(const Window&) = delete;

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

	GLFWwindow* glfwWindow();
private:
	int width;
	int height;
	const char* tittle;
	GLFWwindow* WinMain;

	void Start();
};

#endif // !WINDOW_H
