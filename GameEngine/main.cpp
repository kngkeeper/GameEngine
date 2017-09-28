#include <iostream>
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/IO/input.h"
#include "src/Math/math.h"
#include "src/Utils/fileutils.h"

#include "src/graphics/buffers/buffers.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2D.h"
#include "src/graphics/simple2DRenderer.h"


//Testing out the rendering by drawing a square, this is far too complicated and will be simplified in the future




//very important main loop that incorporates multiple elements of the game engine
int main()
{
	using namespace GameEngine;
	using namespace Graphics;
	using namespace IO;
	using namespace Maths;

	//setting up the window and giving it a name
	Window window("Game Engine", 960, 540);

	std::cout << "Running on OpenGL " << glGetString(GL_VERSION) << std::endl;
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	Renderable2D sprite(vec3(5, 5, 0), vec2(4, 4), vec4(1, 0, 1, 1), shader);

	Renderable2D sprite2(vec3(7, 1, 0), vec2(2, 3), vec4(0, 1, 0, 1), shader);
	Simple2DRenderer renderer;
	vec2 initLightPos(4.0f, 1.5f);
	shader.setUniform2f("light_pos", initLightPos);


	while (!window.Closed())
	{
		window.Clear();
		double x, y;
		x = Input::GetInstance().getX();
		y = Input::GetInstance().getY();
		vec2 LightPos((float)(x * 16.0f / 960.0f), (float)(y * 9.0f / 540.0f));
		shader.setUniform2f("light_pos",LightPos);
		
		renderer.submit(&sprite);
		renderer.submit(&sprite2);

		renderer.flush();


		window.Update();
	}

	return 0;
}

