#include "math.h" 

namespace GameEngine { namespace Maths {

	float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}

	mat4::mat4() 
	{
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;
	}
	mat4::mat4(float diagonal)
	{
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;

		elements[IX(0,0)] = diagonal;
		elements[IX(1,1)] = diagonal;
		elements[IX(2,2)] = diagonal;
		elements[IX(3,3)] = diagonal;
	}

	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}
	mat4& mat4::multiply(const mat4& other)
	{
		mat4 result;
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += elements[IX(x,e)] * other.elements[IX(e,y)];
				}
				result.elements[IX(x,y)] = sum;
			}
		}
		for (int i = 0; i < 4 * 4; i++) {
			this->elements[i] = result.elements[i];
		}
		return *this;
	}

	mat4 operator*(mat4 left, const mat4& right) 
	{
		mat4 result = left.multiply(right);
		return result;
	}

	mat4 mat4::orthographic(float l, float r, float b, float t, float n, float f)
	{
		mat4 result;
		result.elements[IX(0,0)] = 2.0f / (r - l);
		result.elements[IX(1,1)] = 2.0f / (t - b);
		result.elements[IX(2,2)] = 2.0f / (n - f);
		result.elements[IX(0,3)] = (l + r) / (l - r);
		result.elements[IX(1,3)] = (b + t) / (b - t);
		result.elements[IX(2,3)] = (f + n) / (f - n);
		result.elements[IX(3,3)] = 1.0f;
		return result;
	}

	mat4 mat4::perpective(float fov, float aspectRatio, float n, float f)
	{
		mat4 result;
		float q = 1.0f / tan(toRadians(0.5*fov));
		float a = q / aspectRatio;
		float b = (n + f) / (n - f);
		float c = (2.0f * n * f) / (n - f);
		result.elements[IX(0,0)] = a;
		result.elements[IX(1,1)] = q;
		result.elements[IX(2,2)] = b;
		result.elements[IX(3,2)] = -1.0f;
		result.elements[IX(2,3)] = c;

		return result;
	}

	mat4 mat4::translation(const vec3 &translation)
	{
		mat4 result(1.0f);
		result.elements[IX(0,3)] = translation.x;
		result.elements[IX(1,3)] = translation.y;
		result.elements[IX(2,3)] = translation.z;

		return result;
	}

	mat4 mat4::rotation(float angle, const vec3& axis)
	{
		mat4 result(1.0f);
		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		result.elements[IX(0,0)] = axis.x * omc + c;
		result.elements[IX(1,0)] = axis.y* axis.x * omc + axis.z * s;
		result.elements[IX(2,0)] = axis.z* axis.x * omc - axis.y * s;


		result.elements[IX(0,1)] = axis.x * axis.y * omc - axis.z * s;
		result.elements[IX(1,1)] = axis.y * omc + c;
		result.elements[IX(2,1)] = axis.y * axis.z * omc + axis.x * s;

		result.elements[IX(0,2)] = axis.x * axis.z * omc + axis.y * s;
		result.elements[IX(1,2)] = axis.y * axis.z * omc - axis.x * s;
		result.elements[IX(2,2)] = axis.z * omc + c;

		return result;

	}
	mat4 mat4::scale(const vec3& scale)
	{
		mat4 result(1.0f);
		result.elements[IX(0,0)] = scale.x;
		result.elements[IX(1,1)] = scale.y;
		result.elements[IX(2,2)] = scale.z;

		return result;

	}

} }