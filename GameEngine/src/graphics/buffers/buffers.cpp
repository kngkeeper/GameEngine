#include "buffers.h"

namespace GameEngine {
	namespace Graphics {
		Buffer::Buffer(GLfloat * data, GLsizei count, GLuint _componentCount) {
			
			component_Count = _componentCount;

			glGenBuffers(1, &bufferID);
			glBindBuffer(GL_ARRAY_BUFFER, bufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

		}

		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		}

		void Buffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		}

	}
}
