#ifndef VECTOR3_H
#define VECTOR3_H
#include<iostream>
#include<math.h>
#include "../MathEx/MathEx.h"

namespace My
{
	struct Vector3 
	{
	public:
		float x;
		float y;
		float z;

		static Vector3 zero;
		static Vector3 one;
		static Vector3 forward;
		static Vector3 back;
		static Vector3 right;
		static Vector3 left;
		static Vector3 up;
		static Vector3 down;

		Vector3();
		Vector3(float x, float y);
		Vector3(float x, float y, float z);
		Vector3(const Vector3& vector3);
		//Vector3(const Vector2& vector2); para despues

		// static funtions
		static float Angle(Vector3 from, Vector3 to);

		static Vector3 ClampMagnitude(Vector3 vector, float maxLength);

		static float Magnitude(Vector3 vector);

		static float Magnitude(float x, float y, float z);

		static Vector3 Cross(Vector3 a, Vector3 b);

		static float Distance(Vector3 a, Vector3 b);

		static float Dot(Vector3 a, Vector3 b);

		static Vector3 Lerp(Vector3 a, Vector3 b, float t);

		static Vector3 LerpUnclamped(Vector3 a, Vector3 b, float t);

		static Vector3 Max(Vector3 a, Vector3 b);

		static Vector3 Min(Vector3 a, Vector3 b);

		static float SqrMagnitude(Vector3 vector);

		static Vector3 Normalize(Vector3& vector);

		static Vector3 Project(Vector3 vector, Vector3 onNormal);

		static Vector3 Reflect(Vector3 inDirection, Vector3 inNormal);

		void Set(float newX, float newY, float newZ);

		void Scale(Vector3 scale);

		void Normalize();

		Vector3 Normalized();

		//operators
		Vector3& operator = (const Vector3& p);

		friend std::ostream& operator << (std::ostream& o, const Vector3& p)
		{
			o << "[" << p.x << ", " << p.y << ", " << p.z << "]";
			return o;
		}
		friend std::istream& operator >> (std::istream& i, Vector3& p)
		{
			i >> p.x >> p.y >> p.z;
			i.ignore();
			return i;
		}
	};

	Vector3 operator + (Vector3 a, Vector3 b);
	Vector3 operator - (Vector3 a, Vector3 b);
	Vector3 operator * (Vector3 a, Vector3 b);
	Vector3 operator * (Vector3 a, float b);
	Vector3 operator * (float b, Vector3 a);
	Vector3 operator * (Vector3 a, double b);
	Vector3 operator * (double b, Vector3 a);
	Vector3 operator / (Vector3 a,float b);
	bool operator ==(Vector3 a, Vector3 b);
	bool operator !=(Vector3 a, Vector3 b);
}

#endif // !VECTOR3_H
