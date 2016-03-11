#include "Window.hpp"
#include "Shader.hpp"
#include "Vec4.hpp"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	Vec4 vec(1, 2, 3, 4);
	std::cout << "Normal Vector:" << std::endl;
	vec.Print();

	vec.Scale(2);
	std::cout << "\nDoubled Vector: " << std::endl;
	vec.Print();
	
	vec.Scale(0.75f);
	std::cout << "\n1.5 Vector:" << std::endl;
	vec.Print();

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
