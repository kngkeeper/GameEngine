#include <iostream>
#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\IO\input.h"
#include "src\Math\math.h"
#include "src\Utils\fileutils.h"

void test()
{
	GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};
	GLuint vbo, vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}

int main()
{
	using namespace GameEngine;
	using namespace Graphics;
	using namespace IO;
	using namespace Maths;

	Window window("Game Engine", 1024, 768);
	glClearColor(0.2f, 0.1f, 0.7f, 1.0f);

	std::cout << "Running on OpenGL " << glGetString(GL_VERSION) << std::endl;


	test();



	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	while (!window.Closed()) 
	{
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}
	
	return 0;
}

