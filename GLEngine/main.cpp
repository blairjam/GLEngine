#include "Window.hpp"
#include "Shader.hpp"
#include "Matrixf.hpp"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	float aval[] = 
	{
		1, 2, 3,
		4, 5, 6
	};

	float bval[] = 
	{
		7, 8,
		9, 10,
		11, 12
	};

	Matrixf a(2, 3, aval);
	Matrixf b(3, 2, bval);

	try
	{
		Matrixf c = a * b;
		c.Print();
		std::cout << "\nTransposing..." << std::endl;
		c.Transpose();
		c.Print();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

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
