#pragma once

#include "buffers/buffers.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"

#include "../Math/math.h"
#include "shader.h"

namespace GameEngine {
	namespace Graphics {
		class Renderable2D
		{
		protected:
			Maths::vec3 position;
			Maths::vec2 size;
			Maths::vec4 color;

			VertexArray* vertexArray;
			IndexBuffer* indexBuffer;

			Shader& shader;

		public:
		
			Renderable2D(Maths::vec3 _pos, Maths::vec2 _size, Maths::vec4 _col, Shader& _shader)
				: position(_pos),size(_size),color(_col), shader(_shader)
			{
				vertexArray = new VertexArray();
				GLfloat vertices[] =
				{
					0,0,0,
					0,size.y,0,
					size.x,size.y,0,
					size.x,0,0
				};
				GLfloat colors[] =
				{
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w
				};

				vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3),0);
				vertexArray->addBuffer(new Buffer(colors, 4 * 4	, 4), 1);
				
				
				GLuint indices[] = { 0, 1, 2, 2, 3, 0 };
				indexBuffer = new IndexBuffer(indices, 6);
			}

			virtual ~Renderable2D() {
				delete vertexArray;
				delete indexBuffer;
			}

			inline const VertexArray* getVAO() const { return vertexArray; }
			inline IndexBuffer* getIBO() const { return indexBuffer; }

			inline Shader& getShader() const { return shader; }

			inline const Maths::vec3& getPosition() const { return position; }
			inline const Maths::vec2& getSize() const { return size; }
			inline const Maths::vec4& getColor() const { return color; }

		};
	}
}
