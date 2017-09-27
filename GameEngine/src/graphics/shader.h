#pragma once

#include "../Utils/fileutils.h"
#include "../Math/math.h"
#include <vector>
#include <iostream>
#include <GL/glew.h>



namespace GameEngine {
	namespace Graphics {

		class Shader
		{
		private:
			GLuint shaderID;
			GLuint load();
			const char* vertPath;
			const char* fragPath;
		public:
			void setUniformMat4(const GLchar* name, const Maths::mat4& matrix);
			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, Maths::vec2& v);
			void setUniform3f(const GLchar* name, Maths::vec3& v);
			void setUniform4f(const GLchar* name, Maths::vec4& v);
			Shader(const char* _vertPath, const char* _fragPath);
			~Shader();
			void enable() const;
			void disable() const;
		};

} }
