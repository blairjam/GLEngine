#include "Window.hpp"
#include "Shader.hpp"
#include "Vec4.hpp"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	gle::Vec4 vec(1, 2, 3, 0);
	std::cout << "Initial magnitude: " << vec.Length() << std::endl;
	
	vec.Normalize();
	std::cout << "Normalized magnitude: " << vec.Length() << std::endl;

	gle::Window window;

	window.Initialize(argc, argv);

	gle::Shader vertex(GL_VERTEX_SHADER);
	gle::Shader fragment(GL_FRAGMENT_SHADER);
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
