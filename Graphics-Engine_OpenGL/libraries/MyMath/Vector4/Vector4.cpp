#include "Vector4.h"
using namespace My;

Vector4 Vector4::zero = Vector4(0.0f, 0.0f, 0.0f, 0.0f);

Vector4::Vector4(float x, float y, float z, float w)
{
	Vector4::x = x;
	Vector4::y = y;
	Vector4::z = z;
	Vector4::w = w;
}