#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <string>

class Shader
{
private:
	GLenum shaderType;
	std::string characters;
	GLuint id;

	unsigned long CalculateFileLength(std::ifstream&);
	void ReadFile(std::string path);
	void CreateShader();
	void DestroyShader();

public:
	Shader(GLenum);
	Shader(GLenum, std::string);
	~Shader();
	void Create(std::string);
	const GLuint GetId() const;
};

