#ifndef VECTOR4_H
#define VECTOR4_H

namespace My
{
	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		static Vector4 zero;

		Vector4(float x, float y, float z, float w);
	};
}

#endif // !VECTOR4_H
