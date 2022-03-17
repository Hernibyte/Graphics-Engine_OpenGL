#ifndef RENDERER_H
#define RENDERER_H

#include "GLEW/include/GL/glew.h"
#include "ShaderProgramSource.h"
#include "SceneStorage.h"
#include "Animator2D.h"
#include "ShapeRenderer.h"
#include <fstream>
#include <sstream>

class Renderer {
public:
	static Renderer render;

	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;
	Renderer* operator=(const Renderer&) = delete;
	Renderer* operator=(Renderer&&) = delete;

	Renderer();
	~Renderer();

	unsigned int& Program();

	unsigned int& VAO();

	unsigned int& VBO();

	unsigned int& EBO();

	void LoadComponents(Scene& scene);

	void Draw();

	ShaderProgramSource ParceShader(const std::string_view filepath);

	void CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

	void GenerateBuffers();

	void BindBuffers();

	void ClearBuffers();

	void VertexAttributes();

	void GetUniformsLocation();
private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	unsigned int program;

	unsigned int CompileShader(unsigned int type, const std::string& source);
	void GenerateTexture(Texture& tex);

	unsigned int modelLocation;
	unsigned int typeLocation;

	using Shape = std::list<ShapeRenderer*>;
	Shape shape_list;
	using Sprite = std::list<SpriteRenderer*>;
	Sprite sprite_list;
};

#endif // !RENDERER_H
