#pragma once
#include "renderable2D.h"
#include <GL\glew.h>
#include "..\Math\math.h"

namespace GameEngine {
	namespace Graphics {


		class Renderer2D
		{
		public:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	}
}