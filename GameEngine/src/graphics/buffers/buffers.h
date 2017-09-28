#pragma once
#include <GL/glew.h>

namespace GameEngine {
	namespace Graphics {

		class Buffer
		{
		private:
			GLuint bufferID;
			GLuint component_Count;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint _componentCount);

			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() const { return component_Count; }
		};

	}
}
