#include "input.h"

//callbacks are implemented within the window class, should find a way to do the callbacks
//within this class instead for code readability

namespace GameEngine {
	namespace IO {

		Input Input::instance;

		Input& Input::GetInstance() 
		{
			return Input::instance;
		}

		Input::Input() {
			
			//GLFW_KEY_LAST is the max numbers of keys
			for (int i = 0; i < GLFW_KEY_LAST; i++)
			{
				keys[i] = -1;
			}

			//GLFW_MOUSE_BUTTON_LAST is the max number of mouse buttons
			for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++) 
			{
				buttons[i] = -1;
			}

			mouse_x = 0;
			mouse_y = 0;
		}

		double Input::getX()
		{
			return mouse_x;
		}

		double Input::getY()
		{
			return mouse_y;
		}

		void Input::setX(int x)
		{
			mouse_x = x;
		}

		void Input::setY(int y)
		{
			mouse_y = y;
		}

		bool Input::RawKeyboardInput(int key,int action)
		{
			return keys[key] == action;
		}

		bool Input::RawMouseInput(int button, int action)
		{
			return buttons[button] == action;
		}

		void Input::setKey(int key, int action)
		{
			keys[key] = action;
		}
		void Input::setMouseButton(int button, int action)
		{
			buttons[button] = action;
		}
	}
}
