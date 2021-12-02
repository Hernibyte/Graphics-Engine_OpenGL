#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "GLEW/include/GL/glew.h"
#include "GLFW/include/glfw3.h"

class Window {
public:
	static Window window;

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

	void Clear(GLclampf r = 1, GLclampf g = 1, GLclampf b = 1, GLclampf a = 1);
private:
	void Start();

	int width;
	int height;
	const char* tittle;
	GLFWwindow* WinMain;
};

#endif // !WINDOW_H
