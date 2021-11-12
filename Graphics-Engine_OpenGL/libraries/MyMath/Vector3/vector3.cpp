#include "vector3.h"
using namespace My;

//constructors
Vector3::Vector3()
{
	Vector3::x = 0.0f;
	Vector3::y = 0.0f;
	Vector3::z = 0.0f;
}
Vector3::Vector3(float x, float y) 
{
	Vector3::x = x;
	Vector3::y = y;
	Vector3::z = 0.0f;
}
Vector3::Vector3(float x, float y, float z)
{
	Vector3::x = x;
	Vector3::y = y;
	Vector3::z = z;
}
Vector3::Vector3(const Vector3& vector3)
{
	Vector3::x = vector3.x;
	Vector3::y = vector3.y;
	Vector3::z = vector3.z;
}
//static variables
Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);
Vector3 Vector3::one = Vector3(1.0f, 1.0f, 1.0f);
Vector3 Vector3::forward = Vector3(1.0f, 0.0f, 1.0f);
Vector3 Vector3::back = Vector3(1.0f, 0.0f, -1.0f);
Vector3 Vector3::right = Vector3(1.0f, 0.0f, 0.0f);
Vector3 Vector3::left = Vector3(-1.0f, 0.0f, 0.0f);
Vector3 Vector3::up = Vector3(0.0f, 1.0f, 0.0f);
Vector3 Vector3::down = Vector3(0.0f, -1.0f, 0.0f);

//static funtions
float Vector3::Angle(Vector3 from, Vector3 to)
{
	float dotResult = Dot(from, to);
	float magProduct = Magnitude(from) * Magnitude(to);
	float arcosTitha = Acos(dotResult / magProduct);
	return (arcosTitha) / (3.14159265358979323846f / 180);
}
Vector3 Vector3::ClampMagnitude(Vector3 vector, float maxLength)
{
	if (Magnitude(vector) > maxLength)
		return vector.Normalized() * maxLength;
	else
		return vector;
}
float Vector3::Magnitude(float x, float y, float z)
{
	return Sqrt(
		Pow(x, 2) +
		Pow(y, 2) +
		Pow(z, 2));
}
float Vector3::Magnitude(Vector3 vector)
{
	return Magnitude(vector.x, vector.y, vector.z);
}
Vector3 Vector3::Cross(Vector3 a, Vector3 b)
{
	Vector3 result;
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return result;
}
float Vector3::Distance(Vector3 a, Vector3 b)
{
	return Sqrt(
		Pow((a.x - b.x), 2) +
		Pow((a.y - b.y), 2) +
		Pow((a.z - b.z), 2));
}
float Vector3::Dot(Vector3 a, Vector3 b)
{
	return a.x * b.x +
		   a.y * b.y +
		   a.z * b.z;
}
Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
	if (t < 0.0f)
		t = 0.0f;
	else if (t > 1.0f)
		t = 1.0f;
	return LerpUnclamped(a, b, t);
}
Vector3 Vector3::LerpUnclamped(Vector3 a, Vector3 b, float t)
{
	Vector3 result;
	result.x = a.x + (b.x - a.x) * t;
	result.y = a.y + (b.y - a.y) * t;
	result.z = a.z + (b.z - a.z) * t;
	return result;
}
Vector3 Vector3::Max(Vector3 a, Vector3 b)
{
	Vector3 result;
	result.x = (a.x > b.x) ? a.x : b.x;
	result.y = (a.y > b.y) ? a.y : b.y;
	result.z = (a.z > b.z) ? a.z : b.z;
	return result;
}
Vector3 Vector3::Min(Vector3 a, Vector3 b)
{
	Vector3 result;
	result.x = (a.x < b.x) ? a.x : b.x;
	result.y = (a.y < b.y) ? a.y : b.y;
	result.z = (a.z < b.z) ? a.z : b.z;
	return result;
}
float Vector3::SqrMagnitude(Vector3 vector)
{
	return Sqrt(Magnitude(vector));
}
Vector3 Vector3::Normalize(Vector3& vector)
{
	vector.x = vector.x / Magnitude(vector.x, vector.y, vector.z);
	vector.y = vector.y / Magnitude(vector.x, vector.y, vector.z);
	vector.z = vector.z / Magnitude(vector.x, vector.y, vector.z);
	return vector;
}

Vector3 Vector3::Project(Vector3 vector, Vector3 onNormal)
{
	return (Dot(vector, onNormal) / std::pow(Magnitude(onNormal), 2) * onNormal);
}
Vector3 Vector3::Reflect(Vector3 inDirection, Vector3 inNormal)
{
	inNormal.Normalize();
	return inDirection - 2 * (Dot(inDirection, inNormal)) * inNormal;
}

//local funtions
void Vector3::Set(float x, float y, float z)
{
	Vector3::x = x;
	Vector3::y = y;
	Vector3::z = z;
}
void Vector3::Scale(Vector3 scale)
{
	Set(x * scale.x, y * scale.y, z * scale.z);
}
void Vector3::Normalize()
{
	Vector3::x = Vector3::x / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	Vector3::y = Vector3::y / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	Vector3::z = Vector3::z / Magnitude(Vector3::x, Vector3::y, Vector3::z);
}
Vector3 Vector3::Normalized()
{
	Vector3 result;
	result.x = Vector3::x / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	result.y = Vector3::y / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	result.z = Vector3::z / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	return result;
}

 //operators
Vector3& Vector3::operator =(const Vector3& p)
{
	if (this != &p) {
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
	}
	return *this;
}

Vector3 My::operator+(Vector3 a, Vector3 b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3 My::operator-(Vector3 a, Vector3 b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector3 My::operator*(Vector3 a, Vector3 b)
{
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector3 My::operator*(Vector3 a, float b)
{
	return Vector3(a.x * b, a.y * b, a.z * b);
}

Vector3 My::operator*(float b, Vector3 a)
{
	return Vector3(a.x * b, a.y * b, a.z * b);
}

Vector3 My::operator*(Vector3 a, double b)
{
	return Vector3(a.x * (float)b, a.y * (float)b, a.z * (float)b);
}

Vector3 My::operator*(double b, Vector3 a)
{
	return Vector3(a.x * (float)b, a.y * (float)b, a.z * (float)b);
}

Vector3 My::operator/(Vector3 a, float b)
{
	return Vector3(b * (-a.x), b * (-a.y), b * (-a.z));
}

bool My::operator==(Vector3 a, Vector3 b)
{
	float diff_x = a.x - b.x;
	float diff_y = a.y - b.y;
	float diff_z = a.z - b.z;
	float sqrmag = diff_x * diff_x + diff_y * diff_y + diff_z * diff_z;
	return sqrmag < kEpsilon * kEpsilon;
}

bool My::operator!=(Vector3 a, Vector3 b)
{
	return !(a == b);
}