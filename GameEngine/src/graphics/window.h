#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "..\IO\input.h"
#include "..\Math\math.h"



namespace GameEngine {
	namespace Graphics {
		class Window {
		public:
			Window(const char* _name, int _width, int _height);
			~Window();
			bool Closed() const;
			void Clear() const;
			void Update();
			inline int getHeight() const{ return height; }
			inline int getWidth() const { return width; }
		private:
			int width, height;
			const char* name;
			GLFWwindow* window;
			bool init();

		};

		void windowResize(GLFWwindow *window, int width, int height);
		
	}
}