#ifndef RENDERER_H
#define RENDERER_H

#include "GLEW/include/GL/glew.h"
#include "ShaderProgramSource.h"
#include <fstream>
#include <sstream>

class Renderer {
public:
	static Renderer* render;

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

	void Draw();

	ShaderProgramSource ParceShader(const std::string& filepath);

	void CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

	void GenerateBuffers();

	void BindBuffers();

	void ClearBuffers();

	void VertexAttributes();
private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	unsigned int program;

	float vertex[32] = {
		 0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 1.0f
	};
	unsigned int index[6] = {
		0, 1, 3,
		1, 2, 3
	};

	unsigned int CompileShader(unsigned int type, const std::string& source);
};

#endif // !RENDERER_H
