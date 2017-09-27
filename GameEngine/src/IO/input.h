#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

namespace GameEngine{ namespace IO { 

	class Input {
	public:
		static Input& GetInstance();
		double getX();
		double getY();
		void setX(int x);
		void setY(int y);
		bool RawKeyboardInput(int key,int action);
		bool RawMouseInput(int button,int action);
		void setKey(int key, int action);
		void setMouseButton(int button, int action);
	private:
		Input();
		static Input instance;
		double mouse_x, mouse_y;
		int keys[GLFW_KEY_LAST];
		int buttons[GLFW_MOUSE_BUTTON_LAST];
	};

} }
