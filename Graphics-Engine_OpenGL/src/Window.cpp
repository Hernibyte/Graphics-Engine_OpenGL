#include "Window.h"

Window* Window::window = new Window();

Window::Window() : width(1280), height(720), tittle("Window") {
	Start();
}

Window::~Window() {
	glfwTerminate();
	glfwDestroyWindow(WinMain);
}

void Window::Width(int width)  {
	this->width = width;
}

int Window::Width() {
	return width;
}

void Window::Height(int height) {
	this->height = height;
}

int Window::Height() {
	return height;
}

void Window::Tittle(const char* tittle) {
	this->tittle = tittle;
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

void Window::Refresh() {
	glfwSwapBuffers(WinMain);
	glfwPollEvents();
}

void Window::Clear(int r, int g, int b, int a) {
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
	int width, height;
	glfwGetFramebufferSize(WinMain, &width, &height);
	glViewport(0, 0, width, height);
	//
	glewInit();
	//
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
