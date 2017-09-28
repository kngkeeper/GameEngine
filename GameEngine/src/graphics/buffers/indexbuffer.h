#pragma once
#include <GL/glew.h>

namespace GameEngine {
	namespace Graphics {

		class IndexBuffer
		{
		private:
			GLuint bufferID;
			GLuint count;
		public:
			IndexBuffer(GLuint* data, GLsizei _count);

			void bind() const;
			void unbind() const;
			inline GLuint getCount() { return count; }
		};

	}
}
