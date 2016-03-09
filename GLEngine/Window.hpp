#pragma once
#include <string>

class Window
{
private:
	std::string title = "Ch. 1";
	int currentWidth = 800;
	int currentHeight = 600;
	int windowWidth = -1;
	int windowHeight = -1;
	int windowHandle = 0;
	unsigned int frameCount = 0;

public:
	Window();
	~Window();
	void Initialize(int, char*[]);
	void InitWindow(int, char*[]);
	void Resize(int, int);
	void Render();
	void Idle();
	void Timer(int);
};

