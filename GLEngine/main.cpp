#include "Window.hpp"
#include "Shader.hpp"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	Window window;

	window.Initialize(argc, argv);

	Shader vertex(GL_VERTEX_SHADER);
	Shader fragment(GL_FRAGMENT_SHADER);
	try
	{
		vertex.Create("../GLEngine/simple.vert");
		fragment.Create("../GLEngine/simple.frag");
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	glutMainLoop();

	exit(EXIT_SUCCESS);
}
