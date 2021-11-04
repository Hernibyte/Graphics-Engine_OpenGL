#ifndef WINDOW_H
#define WINDOW_H

#include "GLEW/include/GL/glew.h"
#include "GLFW/include/glfw3.h"
#include "Export.h"
#include <iostream>

class ENGINE_API Window {
public:
	static Window* window;

	Window(const Window&) = delete;
	Window(Window&&) = delete;
	Window* operator=(const Window&) = delete;
	Window* operator=(Window&&) = delete;

	Window();
	~Window();

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

	void Clear(int r = 1, int g = 1, int b = 1, int a = 1);
private:
	void Start();

	int width;
	int height;
	const char* tittle;
	GLFWwindow* WinMain;
};

#endif // !WINDOW_H
