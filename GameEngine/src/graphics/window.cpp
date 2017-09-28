#include "Window.h"
namespace GameEngine {
	namespace Graphics {
		//class implements all rendering
		Window::Window(const char* _name, int _width, int _height) 
		{
			name = _name;
			width = _width;
			height = _height;
			if (!init()) {
				glfwTerminate();
			}
		}

		static void mouse_callback(GLFWwindow* window, int button, int action, int mods)
		{
			IO::Input::GetInstance().setMouseButton(button, action);
		}

		static void mouse_location_callback(GLFWwindow* window, double xpos, double ypos)
		{
			int width, height;
			glfwGetWindowSize(window,&width, &height);
			IO::Input::GetInstance().setX(xpos);
			IO::Input::GetInstance().setY(height-ypos);
		}

		static void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			IO::Input::GetInstance().setKey(key, action);
		}

		bool Window::init() {

			//glfw initialization
			if (!glfwInit()) {
				std::cout << "Error initializing GLFW" << std::endl;
				return false;
			}

			window = glfwCreateWindow(width, height, name, NULL, NULL);
			if (!window) {
				glfwTerminate();
				std::cout << "Failed To Create GLFW Window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(window);
			glfwSetWindowSizeCallback(window, windowResize);

			glfwSetKeyCallback(window, keyboard_callback);
			glfwSetMouseButtonCallback(window, mouse_callback);
			glfwSetCursorPosCallback(window, mouse_location_callback);
			//glew initialization
			if (glewInit() != GLEW_OK) {
				std::cout << "Error initializing GLEW!" << std::endl;
				return false;
			}



			return true;
		}

		Window::~Window() 
		{
			glfwTerminate();
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update() 
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
			{
				std::cout << "OpenGL error: " << error << std::endl;
			}


			glfwPollEvents();
			glfwSwapBuffers(window);
		}



		bool Window::Closed() const
		{
			return glfwWindowShouldClose(window);
		}

		void windowResize(GLFWwindow *window, int _width, int _height) 
		{
			glViewport(0, 0, _width, _height);
		}

	}
}