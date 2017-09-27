#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#define IX(i,j) ((i)+(j*4))


namespace GameEngine { namespace Maths {
	struct vec2{
		float x, y;
		vec2(float x0, float y0)
		{
			x = x0;
			y = y0;
		}
		bool operator==(const vec2 &v) const
		{
			return (v.x == x && v.y == y);
		}
		bool operator!=(const vec2 &v) const
		{
			return !(*this == v);
		}
		double operator[](int i) const
		{
			return (i == 0 ? x : y);
		}
		vec2 operator+(const vec2 &v) const
		{
			return vec2(x + v.x, y + v.y);
		}
		vec2 & operator+=(const vec2 &v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		vec2 operator - (const vec2 &v)
		{
			return *this + -v;
		}

		vec2 & operator -=(const vec2 &v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}

		vec2 operator-() const {
			return vec2(-x, -y);
		}

		vec2 operator*(const double c) const
		{
			return vec2(x*c, y*c);
		}

		vec2 & operator *= (double c)
		{
			x *= c;
			y *= c;
			return *this;
		}

		vec2 operator/(const double c) const
		{
			return vec2(x / c, y / c);
		}

		vec2 & operator/=(const double c)
		{
			*this = *this / c;
			return *this;
		}		
	};

	struct vec3
	{
		float x, y, z;
		vec3(float x0, float y0, float z0)
		{
			x = x0;
			y = y0;
			z = z0;
		}
		bool operator==(const vec3 &v) const
		{
			return (v.x == x && v.y == y && v.z == z);
		}
		bool operator!=(const vec3 &v) const
		{
			return !(*this == v);
		}
		double operator[](int i) const
		{
			return (i == 0 ? x : (i == 1 ? y : z));
		}
		vec3 operator+(const vec3 &v) const
		{
			return vec3(x + v.x, y + v.y, z + v.z);
		}
		vec3 & operator+=(const vec3 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		vec3 operator - (const vec3 &v)
		{
			return *this + -v;
		}

		vec3 & operator -=(const vec3 &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}

		vec3 operator-() const {
			return vec3(-x, -y, -z);
		}

		vec3 operator*(const double c) const
		{
			return vec3(x*c, y*c, z*c);
		}

		vec3 & operator *= (double c)
		{
			x *= c;
			y *= c;
			z *= c;
			return *this;
		}

		vec3 operator/(const double c) const
		{
			return vec3(x / c, y / c, z / c);
		}

		vec3 & operator/=(const double c)
		{
			*this = *this / c;
			return *this;
		}
	};

	struct vec4
	{
		float x, y, z, w;
		vec4() = default;
		vec4(float x0, float y0, float z0, float w0)
		{
			x = x0;
			y = y0;
			z = z0;
			w = w0;
		}
		bool operator==(const vec4 &v) const
		{
			return (v.x == x && v.y == y && v.z == z && v.w==w);
		}
		bool operator!=(const vec4 &v) const
		{
			return !(*this == v);
		}
		double operator[](int i) const
		{
			return (i == 0 ? x : (i == 1 ? y : (i == 2 ? z: w)));
		}
		vec4 operator+(const vec4 &v) const
		{
			return vec4(x + v.x, y + v.y, z + v.z, w+v.w);
		}
		vec4 & operator+=(const vec4 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}

		vec4 operator - (const vec4 &v)
		{
			return *this + -v;
		}

		vec4 & operator -=(const vec4 &v)
		{
			x -= v.x;
			y -= v.y;
			w -= v.w;
			z -= v.z;
			return *this;
		}

		vec4 operator-() const {
			return vec4(-x, -y,-z,-w);
		}

		vec4 operator*(const double c) const
		{
			return vec4(x*c, y*c, z*c, w*c);
		}

		vec4 & operator *= (double c)
		{
			x *= c;
			y *= c;
			z *= c;
			w *= c;
			return *this;
		}

		vec4 operator/(const double c) const
		{
			return vec4(x / c, y / c,z/c,w/c);
		}

		vec4 & operator/=(const double c)
		{
			*this = *this / c;
			return *this;
		}
	};

	struct mat4
	{
		union
		{
			float elements[4 * 4];
			vec4 columns[4];
		};
		mat4();
		mat4(float diagonal);

		static mat4 identity();
		mat4& multiply(const mat4& other);
		
		static mat4 orthographic(float l, float r, float b, float t, float n, float f);
		static mat4 perpective(float fov, float aspectRatio, float n, float f);

		static mat4 translation(const vec3 &translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);

		friend mat4 operator*(mat4 left, const mat4& right);
	};

	float toRadians(float degrees);

}}

