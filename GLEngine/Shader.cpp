#include "Shader.hpp"
#include <fstream>
#include <exception>
#include <iostream>

gle::Shader::Shader(GLenum type) : Shader(type, "")
{
}

gle::Shader::Shader(GLenum type, std::string path)
{
	shaderType = type;
	id = 0;

	if (!path.empty())
	{
		Create(path);
	}
}

gle::Shader::~Shader()
{
	DestroyShader();
}

void gle::Shader::Create(std::string path)
{
	ReadFile(path);
	CreateShader();
}

const GLuint gle::Shader::GetId() const
{
	return id;
}

unsigned long gle::Shader::CalculateFileLength(std::ifstream& file)
{
	unsigned long length = 0;

	if (file.good())
	{
		file.seekg(0, std::ios::end);
		length = file.tellg();
		file.seekg(std::ios::beg);
	}

	return length;
}

void gle::Shader::ReadFile(std::string path)
{
	std::ifstream file;

	file.open(path, std::ios::in);

	if (!file)
	{
		throw std::runtime_error("Shader cannot be found at: " + path);
	}

	unsigned long length = CalculateFileLength(file);

	if (length == 0)
	{
		throw std::runtime_error("Shader file given at " + path + " is has a length of 0.");
	}

	char next;
	while (!file.eof())
	{
		file.get(next);
		characters.push_back(next);
	}

	characters.shrink_to_fit();

	file.close();
}

void gle::Shader::CreateShader()
{
	GLenum errorCheckValue = glGetError();

	id = glCreateShader(shaderType);

	if (id == 0)
	{
		throw std::runtime_error("Shader ID could not be created for shader type: " + std::to_string(shaderType));
	}

	const GLchar* source = characters.c_str();

	glShaderSource(id, 1, &source, 0);
	glCompileShader(id);

	GLint compileStatus;

	glGetShaderiv(id, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus != GL_TRUE)
	{
		throw std::runtime_error("Shader " + std::to_string(id) + " could not be compiled.");
	}

	errorCheckValue = glGetError();

	if (errorCheckValue != GL_NO_ERROR)
	{
		throw std::runtime_error("Shader creation failed.");
	}
}

void gle::Shader::DestroyShader()
{
	GLenum errorCheckValue = glGetError();

	glDeleteShader(id);

	errorCheckValue = glGetError();

	if (errorCheckValue != GL_NO_ERROR)
	{
		throw std::runtime_error("Shader " + std::to_string(id) + " could not be deleted.");
	}
}
