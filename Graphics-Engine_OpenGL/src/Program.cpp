#include "Program.h"

Program::Program() {
	Window::window.Width(800);
	Window::window.Height(800);
	Window::window.Tittle("Window");
}

Program::Program(int width, int height, const char* tittle) {
	Window::window.Width(width);
	Window::window.Height(height);
	Window::window.Tittle(tittle);
}

void Program::Run() {
	Init();

	Core_Awake();
	Awake();

	Core_Start();
	Start();

	while (!Window::window.IsWindowShouldClose()) {
		Time::Start();

		Window::window.Clear(0, 0, 0, 0);

		Core_LateUpdate();
		LateUpdate();

		Core_Update();
		Update();

		Core_FixedUpdate();
		FixedUpdate();

		Window::window.Refresh();

		Time::Tick();
	}

	Core_Sleep();
	Sleep();
}

Scene* Program::CreateScene(std::string_view name) {
	return SceneStorage.CreateScene(name);
}

Scene* Program::GetScene(std::string_view name) {
	return SceneStorage.GetScene(name);
}

void Program::SetMainScene(std::string_view name) {
	mainScene = name.data();
}

void Program::SetMainScene(Scene* scene) {
	mainScene = scene->Name();
}

void Program::Core_Awake() {
	ShaderProgramSource source = Renderer::render.ParceShader("src/StandardShader/StandardShader.glsl");
	Renderer::render.CreateProgram(source.Vertex, source.Fragment);
	//
	Renderer::render.GenerateBuffers();
	Renderer::render.BindBuffers();
	Renderer::render.VertexAttributes();
	Renderer::render.GetUniformsLocation();
	Renderer::render.LoadComponents(*SceneStorage.GetScene(mainScene));
	
	for (auto& g : SceneStorage.GetScene(mainScene)->GetAllObjects())
		g->Awake();
}

void Program::Core_Start() {
	
	for (auto& g : SceneStorage.GetScene(mainScene)->GetAllObjects())
		g->Start();
}

void Program::Core_LateUpdate() {
	collision_manager.CheckCollisions();

	for (auto& g : SceneStorage.GetScene(mainScene)->GetAllObjects())
		g->LateUpdate();
}

void Program::Core_Update() {
	Renderer::render.Draw();

	for (auto& g : SceneStorage.GetScene(mainScene)->GetAllObjects())
		g->Update();
}

void Program::Core_FixedUpdate() {
	for (auto& g : SceneStorage.GetScene(mainScene)->GetAllObjects())
		g->FixedUpdate();
}

void Program::Core_Sleep() {

}
