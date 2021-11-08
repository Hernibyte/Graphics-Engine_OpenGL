#include "Program.h"

Program::Program() {
	Window::window.Width(1280);
	Window::window.Height(720);
	Window::window.Tittle("Window");
}

Program::Program(int width, int height, const char* tittle) {
	Window::window.Width(width);
	Window::window.Height(height);
	Window::window.Tittle(tittle);
}

void Program::Run() {
	Core_Awake();
	Awake();

	Core_Start();
	Start();

	Window::window.SetWindowShouldClose(true);

	while (Window::window.IsWindowShouldClose()) {
		Window::window.Clear();

		Core_LateUpdate();
		LateUpdate();

		Core_Update();
		Update();

		Core_FixedUpdate();
		FixedUpdate();

		Window::window.Refresh();
	}

	Core_Sleep();
	Sleep();
}

void Program::Core_Awake() {
	ShaderProgramSource source = Renderer::render.ParceShader("src/StandardShader/StandardShader.glsl");
	Renderer::render.CreateProgram(source.Vertex, source.Fragment);
	//
	Renderer::render.GenerateBuffers();
	Renderer::render.BindBuffers();
	Renderer::render.VertexAttributes();
}

void Program::Core_Start() {

}

void Program::Core_LateUpdate() {
	Renderer::render.Draw();
}

void Program::Core_Update() {

}

void Program::Core_FixedUpdate() {

}

void Program::Core_Sleep() {

}
