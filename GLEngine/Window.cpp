#include "Window.hpp"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <cstdlib>
#include <iostream>
#include <memory>

Window* Instance = nullptr;

extern "C" void ResizeFunction(int width, int height)
{
	Instance->Resize(width, height);
}

extern "C" void RenderFunction()
{
	Instance->Render();
}

extern "C" void IdleFunction()
{
	Instance->Idle();
}

extern "C" void TimerFunction(int value)
{
	Instance->Timer(value);
}

Window::Window()
{
	Instance = this;
}

Window::~Window()
{
}

void Window::Initialize(int argc, char* argv[])
{
	GLenum glewInitResult;

	InitWindow(argc, argv);

	glewInitResult = glewInit();

	if (glewInitResult != GLEW_OK)
	{
		std::cerr << "ERROR: " << glewGetErrorString(glewInitResult) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Window::InitWindow(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 0);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	windowWidth = glutGet(GLUT_SCREEN_WIDTH);
	windowHeight = glutGet(GLUT_SCREEN_HEIGHT);

	glutInitWindowSize(currentWidth, currentHeight);
	glutInitWindowPosition((windowWidth - currentWidth) / 2, (windowHeight - currentHeight) / 2);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	windowHandle = glutCreateWindow(title.c_str());

	if (windowHandle < 1)
	{
		std::cerr << "ERROR: Could not create a new rendering window." << std::endl;
		exit(EXIT_FAILURE);
	}

	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
	glutIdleFunc(IdleFunction);
	glutTimerFunc(0, TimerFunction, 0);
}

void Window::Resize(int width, int height)
{
	currentWidth = width;
	currentHeight = height;

	glViewport(0, 0, currentWidth, currentHeight);
}

void Window::Render()
{
	++frameCount;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();
	glutPostRedisplay();
}

void Window::Idle()
{
	glutPostRedisplay();
}

void Window::Timer(int value)
{
	if (value != 0)
	{
		std::string newTitle = title;

		newTitle += " " + std::to_string(frameCount * 4) + "fps @ " + std::to_string(currentWidth) + "x" + std::to_string(currentHeight);

		glutSetWindowTitle(newTitle.c_str());
	}

	frameCount = 0;

	glutTimerFunc(250, TimerFunction, 1);
}
