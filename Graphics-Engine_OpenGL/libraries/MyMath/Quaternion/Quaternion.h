#ifndef QUATERNION_H
#define QUATERNION_H
#include "../MathEx/MathEx.h"
#include "../Vector3/vector3.h"

using namespace My;

namespace My 
{
	struct Quaternion
	{
		float x;
		float y;
		float z;
		float w;

		float Get(int index);
		void Set(int index, float value);

		static Quaternion identity;

		Quaternion Normalized();

		Vector3 EulerAngles();
		void EulerAngles(Vector3 value);

		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(const Quaternion& quaternion);
		Quaternion(Vector3 vector, float w);

		void Set(float x, float y, float z, float w);
		void Set(Quaternion quaternion);

		void Normalize();

		void SetFromToRotation(Vector3 fromDirection, Vector3 toDirection);

		void SetLookRotation(Vector3 view);
		void SetLookRotation(Vector3 view, Vector3 up);

		//void ToAngleAxis();

		//Static methods
		static float Angle(Quaternion a, Quaternion b);

		static Quaternion AngleAxis(float angle, Vector3 axis);

		static float Dot(Quaternion a, Quaternion b);

		static Quaternion Euler(Vector3 euler);

		static Quaternion FromToRotation(Vector3 fromDirection, Vector3 toDirection);

		static Quaternion Inverse(Quaternion& rotation);

		static Quaternion Lerp(Quaternion a, Quaternion b, float t);

		static Quaternion LerpUnclamped(Quaternion a, Quaternion b, float t);

		static Quaternion LookRotation(Vector3 forward);
		static Quaternion LookRotation(Vector3& forward, Vector3& up);

		static Quaternion Normalize(Quaternion& quaternion);

		static Quaternion RotateTowards(Quaternion from, Quaternion to, float maxDegreesDelta);

		static Quaternion Slerp(Quaternion a, Quaternion b, float t);

		static Quaternion SlerpUnclamped(Quaternion a, Quaternion b, float t);

		// Operators

	};

	//Vector3 operator*(Quaternion a, Quaternion b);
	Quaternion operator*(Quaternion a, Quaternion b);
	bool operator==(Quaternion a, Quaternion b);
	bool operator!=(Quaternion a, Quaternion b);
}

#endif // !QUATERNION_H
