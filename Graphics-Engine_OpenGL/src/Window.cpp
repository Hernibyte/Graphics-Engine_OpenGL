#include "Window.h"

Window Window::window;

Window::Window() : width(100), height(100), tittle("Window") {
	Start();
}

Window::~Window() {
	glfwTerminate();
	glfwDestroyWindow(WinMain);
}

void Window::Width(int width)  {
	this->width = width;
	UpdateAttributes();
}

int Window::Width() {
	return width;
}

void Window::Height(int height) {
	this->height = height;
	UpdateAttributes();
}

int Window::Height() {
	return height;
}

void Window::Tittle(const char* tittle) {
	this->tittle = tittle;
	UpdateAttributes();
}

const char* Window::Tittle() {
	return tittle;
}

GLFWwindow* Window::glfwWindow() {
	return WinMain;
}

void Window::SetWindowShouldClose(bool state) {
	glfwSetWindowShouldClose(WinMain, state);
}

bool Window::IsWindowShouldClose() {
	return glfwWindowShouldClose(WinMain);
}

void Window::UpdateAttributes() {
	glfwSetWindowTitle(WinMain, tittle);
	glfwSetWindowSize(WinMain, width, height);
	glViewport(0, 0, width, height);
}

void Window::Refresh() {
	glfwSwapBuffers(WinMain);
	glfwPollEvents();
}

void Window::Clear(GLclampf r, GLclampf g, GLclampf b, GLclampf a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Start() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//
	WinMain = glfwCreateWindow(width, height, tittle, NULL, NULL);
	if (WinMain == NULL) {
		std::cout << "Failed to create Window" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	//
	glfwMakeContextCurrent(WinMain);
	//
	int _width, _height;
	glfwGetFramebufferSize(WinMain, &_width, &_height);
	glViewport(0, 0, _width, _height);
	//
	glewInit();
	//
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
