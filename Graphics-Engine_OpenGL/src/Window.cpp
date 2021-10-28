#include "Window.h"

Window* Window::window = nullptr;

Window::Window() : width(1280), height(720), tittle("Standard") {
	WinMain = NULL;
	//
	Start();
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

void Window::Start() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//
	WinMain = glfwCreateWindow(width, height, tittle, NULL, NULL);
	if (WinMain == NULL) {
		std::cout << "Failed to c reate Window" << std::endl;
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
