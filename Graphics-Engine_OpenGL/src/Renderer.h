#ifndef RENDERER_H
#define RENDERER_H

#include "GLEW/include/GL/glew.h"
#include "ShaderProgramSource.h"
#include <fstream>
#include <sstream>

class Renderer {
public:
	static Renderer* render;

	Renderer();
	~Renderer();

	unsigned int& Program();

	unsigned int& VAO();

	unsigned int& VBO();

	unsigned int& EBO();

	void Draw();

private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	unsigned int program;

	void GenerateBuffers();

	void BindBuffers();

	void ClearBuffers();

	void VertexAttributes();

	ShaderProgramSource ParceShader(const std::string& filepath);

	unsigned int CompileShader(unsigned int type, const std::string& source);

	void CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
};

#endif // !RENDERER_H
