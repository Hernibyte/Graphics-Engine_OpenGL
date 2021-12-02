#include "InputSystem.h"

bool InputSystem::GetKey(int KeyCode) {
	return glfwGetKey(Window::window.glfwWindow(), KeyCode) == GLFW_PRESS;
}

bool InputSystem::GetKeyMouse(int KeyCode) {
	return glfwGetMouseButton(Window::window.glfwWindow(), KeyCode) == GLFW_PRESS;
}