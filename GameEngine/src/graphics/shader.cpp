#pragma once
#include "shader.h"

namespace GameEngine { namespace Graphics{
	void Shader::setUniformMat4(const GLchar * name, const Maths::mat4 & matrix)
	{
		glUniformMatrix4fv(glGetUniformLocation(shaderID, name), 1, GL_FALSE, matrix.m.elements);
	}
	void Shader::setUniform1f(const GLchar * name, float value)
	{
		glUniform1f(glGetUniformLocation(shaderID,name), value);
	}
	void Shader::setUniform1i(const GLchar * name, int value)
	{
		glUniform1i(glGetUniformLocation(shaderID,name), value);
	}
	void Shader::setUniform2f(const GLchar * name, Maths::vec2 & v)
	{
		glUniform2f(glGetUniformLocation(shaderID,name), v.x, v.y);
	}
	void Shader::setUniform3f(const GLchar * name, Maths::vec3 & v)
	{
		glUniform3f(glGetUniformLocation(shaderID,name), v.x, v.y, v.z);
	}
	void Shader::setUniform4f(const GLchar * name, Maths::vec4 & v)
	{
		glUniform4f(glGetUniformLocation(shaderID,name), v.x, v.y, v.z, v.w);
	}
	Shader::Shader(const char* _vertPath, const char* _fragPath)
	{
		vertPath = _vertPath;
		fragPath = _fragPath;

		shaderID = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(shaderID);
	}

	void Shader::enable() const
	{
		glUseProgram(shaderID);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLuint vert = glCreateShader(GL_VERTEX_SHADER);
		GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vsrcstring = read_file(vertPath);
		std::string fsrcstring = read_file(fragPath);

		const char* vertsrc = vsrcstring.c_str();
		const char* fragsrc = fsrcstring.c_str();

		glShaderSource(vert, 1, &vertsrc, NULL );
		glCompileShader(vert);

		GLint result;
		glGetShaderiv(vert, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vert, length, &length, &error[0]);
			std::string e(error.begin(), error.end());
			std::cout << "Failed to compile vertex shader!/n" << e << std::endl;
			glDeleteShader(vert);
			return 0;
		}

		glShaderSource(frag, 1, &fragsrc, NULL);
		glCompileShader(frag);

		glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(frag, length, &length, &error[0]);
			std::string e(error.begin(), error.end());
			std::cout << "Failed to compile fragment shader!/n" << e << std::endl;
			glDeleteShader(frag);
			return 0;
		}

		glAttachShader(program, vert);
		glAttachShader(program, frag);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vert);
		glDeleteShader(frag);

		return program;
	}
}}
