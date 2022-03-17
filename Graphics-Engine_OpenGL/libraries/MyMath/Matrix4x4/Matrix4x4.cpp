#include "Matrix4x4.h"
using namespace My;

Matrix4x4 Matrix4x4::identity = Matrix4x4(
									Vector4(1, 0, 0, 0),
									Vector4(0, 1, 0, 0),
									Vector4(0, 0, 1, 0),
									Vector4(0, 0, 0, 1));

Matrix4x4 Matrix4x4::zero = Matrix4x4(
									Vector4(0, 0, 0, 0),
									Vector4(0, 0, 0, 0),
									Vector4(0, 0, 0, 0),
									Vector4(0, 0, 0, 0));

Matrix4x4 Matrix4x4::transpose() 
{
	return Matrix4x4(
				Vector4(value[0], value[1], value[2], value[3]),
				Vector4(value[4], value[5], value[6], value[7]),
				Vector4(value[8], value[9], value[10], value[11]),
				Vector4(value[12], value[13], value[14], value[15]));
}

Vector3 Matrix4x4::lossyScale() 
{
	return Vector3(value[0], value[5], value[10]);
}

Matrix4x4::Matrix4x4() {
	for (int i = 0; i < 16; i++) 
	{
		value[i] = 0.0f;
	}
}

Matrix4x4::Matrix4x4(Vector4 column0, Vector4 column1, Vector4 column2, Vector4 column3)
{
	value[0] = column0.x;
	value[1] = column1.x;
	value[2] = column2.x;
	value[3] = column3.x;
	value[4] = column0.y;
	value[5] = column1.y;
	value[6] = column2.y;
	value[7] = column3.y;
	value[8] = column0.z;
	value[9] = column1.z;
	value[10] = column2.z;
	value[11] = column3.z;
	value[12] = column0.w;
	value[13] = column1.w;
	value[14] = column2.w;
	value[15] = column3.w;
}

Matrix4x4::Matrix4x4(const Matrix4x4& matrix)
{
	for (int i = 0; i < 16; i++) 
	{
		value[i] = matrix.value[i];
	}
}

Vector4 Matrix4x4::GetColumn(int index)
{
	switch (index)
	{
	case 0:
		return Vector4(value[0], value[4], value[8], value[12]);
		break;
	case 1:
		return Vector4(value[1], value[5], value[9], value[13]);
		break;
	case 2:
		return Vector4(value[2], value[6], value[10], value[14]);
		break;
	case 3:
		return Vector4(value[3], value[7], value[11], value[15]);
		break;
	default:
		throw "Out of range: Use 0, 1, 2 or 3";
		break;
	}
}

Vector4 Matrix4x4::GetRow(int index)
{
	switch (index)
	{
	case 0:
		return Vector4(value[0], value[1], value[2], value[3]);
		break;
	case 1:
		return Vector4(value[4], value[5], value[6], value[7]);
		break;
	case 2:
		return Vector4(value[8], value[9], value[10], value[11]);
		break;
	case 3:
		return Vector4(value[12], value[13], value[14], value[15]);
		break;
	default:
		throw "Out of range: Use 0, 1, 2 or 3";
		break;
	}
}

void Matrix4x4::SetColumn(int index, Vector4 column)
{
	switch (index)
	{
	case 0:
		value[0] = column.x;
		value[4] = column.y;
		value[8] = column.z;
		value[12] = column.w;
		break;
	case 1:
		value[1] = column.x;
		value[5] = column.y;
		value[9] = column.z;
		value[13] = column.w;
		break;
	case 2:
		value[2] = column.x;
		value[6] = column.y;
		value[10] = column.z;
		value[14] = column.w;
		break;
	case 3:
		value[3] = column.x;
		value[7] = column.y;
		value[11] = column.z;
		value[15] = column.w;
		break;
	default:
		throw "Out of range: Use 0, 1, 2 or 3";
		break;
	}
}

void Matrix4x4::SetRow(int index, Vector4 row)
{
	switch (index) {
	case 0:
		value[0] = row.x;
		value[1] = row.y;
		value[2] = row.z;
		value[3] = row.w;
		break;
	case 1:
		value[4] = row.x;
		value[5] = row.y;
		value[6] = row.z;
		value[7] = row.w;
		break;
	case 2:
		value[8] = row.x;
		value[9] = row.y;
		value[10] = row.z;
		value[11] = row.w;
		break;
	case 3:
		value[12] = row.x;
		value[13] = row.y;
		value[14] = row.z;
		value[15] = row.w;
		break;
	default:
		throw "Out of range: Use 0, 1, 2 or 3";
		break;
	}
}

float* Matrix4x4::Value_ptr()
{
	return &value[0];
}

float* Matrix4x4::Value_ptr(int i)
{
	if (i < 15 && i > 0)
		return &value[i];
}

void Matrix4x4::Projection(const float& angleOfView, const float& near, const float& far)
{
	float scale = static_cast<float>(1 / Tan(angleOfView * 0.5 * PI / 180));
	value[0] = scale;
	value[5] = scale;
	value[10] = -far / (far - near);
	value[14] = -far * near / (far - near);
	value[11] = -1;
	value[15] = 0;
}

void Matrix4x4::Orthographic(const float& buttom, const float& top, const float& left, const float& right, 
							 const float& near, const float& far)
{
	value[0] = 2 / (right - left);
	value[5] = 2 / (top - buttom);
	value[10] = -2 / (far - near);
	value[12] = -(right + left) / (right - left);
	value[13] = -(top + buttom) / (top - buttom);
	value[14] = -(far + near) / (far - near);
}

void Matrix4x4::TRS(Vector3 position, Quaternion rotation, Vector3 scale)
{
	Translate(position);
	Rotate(rotation);
	Scale(scale);
}

void Matrix4x4::Translate(Vector3 translate) 
{
	this->value[3] += translate.x;
	this->value[7] += translate.y;
	this->value[11] += translate.z;
	this->value[15] = 1;
}

void Matrix4x4::Scale(Vector3 scale)
{
	this->value[0] *= scale.x;
	this->value[5] *= scale.y;
	this->value[10] *= scale.z;
	this->value[15] = 1;
}

void Matrix4x4::Rotate(Quaternion quaternion)
{
	this->value[2] = 2.0f * (quaternion.x * quaternion.z) + 2.0f * (quaternion.y * quaternion.w);
	this->value[6] = 2.0f * (quaternion.y * quaternion.z) - 2.0f * (quaternion.x * quaternion.w);
	this->value[10] = 1 - 2.0f * (quaternion.x * quaternion.x) - 2.0f * (quaternion.y * quaternion.y);
	
	this->value[0] = 1 - 2.0f * (quaternion.y * quaternion.y) - 2.0f * (quaternion.z * quaternion.z);
	this->value[4] = 2.0f * (quaternion.x * quaternion.y) + 2.0f * (quaternion.z * quaternion.w);
	this->value[8] = 2.0f * (quaternion.x * quaternion.z) - 2.0f * (quaternion.y * quaternion.w);
	
	this->value[1] = 2.0f * (quaternion.x * quaternion.y) - 2.0f * (quaternion.z * quaternion.w);
	this->value[5] = 1 - 2.0f * (quaternion.x * quaternion.x) - 2.0f * (quaternion.z * quaternion.z);
	this->value[9] = 2.0f * (quaternion.y * quaternion.z) + 2.0f * (quaternion.x * quaternion.w);
}

float* Matrix4x4::Value_ptr(Matrix4x4 matrix, int i)
{
	if (i < 15 && i > 0)
		return &matrix.value[i];
}

float* Matrix4x4::Value_ptr(Matrix4x4 matrix)
{
	return &matrix.value[0];
}

Matrix4x4 Matrix4x4::Projection(const float& angleOfView, const float& near, const float& far, Matrix4x4 matrix)
{
	float scale = static_cast<float>(1 / Tan(angleOfView * 0.5 * PI / 180));
	matrix.value[0] = scale;
	matrix.value[5] = scale;
	matrix.value[10] = -far / (far - near);
	matrix.value[14] = -far * near / (far - near);
	matrix.value[11] = -1;
	matrix.value[15] = 0;

	return matrix;
}

Matrix4x4 Matrix4x4::Orthographic(const float& buttom, const float& top, const float& left, const float& right,
								  const float& near, const float& far, Matrix4x4 matrix)
{
	matrix.value[0] = 2 / (right - left);
	matrix.value[5] = 2 / (top - buttom);
	matrix.value[10] = -2 / (far - near);
	matrix.value[12] = -(right + left) / (right - left);
	matrix.value[13] = -(top + buttom) / (top - buttom);
	matrix.value[14] = -(far + near) / (far - near);

	return matrix;
}

Matrix4x4 Matrix4x4::Rotate(Matrix4x4 matrix, Quaternion quaternion)
{
	matrix.value[2] = 2.0f * (quaternion.x * quaternion.z) + 2.0f * (quaternion.y * quaternion.w);
	matrix.value[6] = 2.0f * (quaternion.y * quaternion.z) - 2.0f * (quaternion.x * quaternion.w);
	matrix.value[10] = 1 - 2.0f * (quaternion.x * quaternion.x) - 2.0f * (quaternion.y * quaternion.y);

	matrix.value[0] = 1 - 2.0f * (quaternion.y * quaternion.y) - 2.0f * (quaternion.z * quaternion.z);
	matrix.value[4] = 2.0f * (quaternion.x * quaternion.y) + 2.0f * (quaternion.z * quaternion.w);
	matrix.value[8] = 2.0f * (quaternion.x * quaternion.z) - 2.0f * (quaternion.y * quaternion.w);

	matrix.value[1] = 2.0f * (quaternion.x * quaternion.y) - 2.0f * (quaternion.z * quaternion.w);
	matrix.value[5] = 1 - 2.0f * (quaternion.x * quaternion.x) - 2.0f * (quaternion.z * quaternion.z);
	matrix.value[9] = 2.0f * (quaternion.y * quaternion.z) + 2.0f * (quaternion.x * quaternion.w);
	return matrix;
}

Matrix4x4 Matrix4x4::Scale(Matrix4x4 matrix, Vector3 scale)
{
	matrix.value[0] *= scale.x;
	matrix.value[5] *= scale.y;
	matrix.value[10] *= scale.z;
	matrix.value[15] = 1;
	return matrix;
}

Matrix4x4 Matrix4x4::Translate(Matrix4x4 matrix, Vector3 translate)
{
	matrix.value[3] += translate.x;
	matrix.value[7] += translate.y;
	matrix.value[11] += translate.z;
	matrix.value[15] = 1;
	return matrix;
}

Matrix4x4 Matrix4x4::TRS(Matrix4x4 matrix, Matrix4x4 translate, Matrix4x4 rotate, Matrix4x4 scale)
{
	matrix = translate * rotate * scale;
	return matrix;
}

Matrix4x4 Matrix4x4::TRS(Matrix4x4 translate, Matrix4x4 rotate, Matrix4x4 scale, Vector3 position, Quaternion rotation, Vector3 scalar)
{
	translate = Translate(translate, position);
	rotate = Rotate(rotate, rotation);
	scale = Scale(scale, scalar);
	Matrix4x4 trs = translate * rotate * scale;
	return trs;
}

Vector4 My::operator*(Matrix4x4 a, Vector4 vector)
{
	Vector4 newVec4 = Vector4::zero;
	newVec4.x = (a.value[0] * vector.x) + (a.value[1] * vector.y) + (a.value[2] * vector.z) + (a.value[3] * vector.w);
	newVec4.y = (a.value[4] * vector.x) + (a.value[5] * vector.y) + (a.value[6] * vector.z) + (a.value[7] * vector.w);
	newVec4.z = (a.value[8] * vector.x) + (a.value[9] * vector.y) + (a.value[10] * vector.z) + (a.value[11] * vector.w);
	newVec4.w = (a.value[12] * vector.x) + (a.value[13] * vector.y) + (a.value[14] * vector.z) + (a.value[15] * vector.w);
	return newVec4;
}

Matrix4x4 My::operator*(Matrix4x4 a, Matrix4x4 b)
{
	Matrix4x4 matXMat = Matrix4x4::zero;
	matXMat.value[0] = (a.value[0] * b.value[0]) + (a.value[1] * b.value[4]) + (a.value[2] * b.value[8]) + (a.value[3] * b.value[12]);
	matXMat.value[1] = (a.value[0] * b.value[1]) + (a.value[1] * b.value[5]) + (a.value[2] * b.value[9]) + (a.value[3] * b.value[13]);
	matXMat.value[2] = (a.value[0] * b.value[2]) + (a.value[1] * b.value[6]) + (a.value[2] * b.value[10]) + (a.value[3] * b.value[14]);
	matXMat.value[3] = (a.value[0] * b.value[3]) + (a.value[1] * b.value[7]) + (a.value[2] * b.value[11]) + (a.value[3] * b.value[15]);

	matXMat.value[4] = (a.value[4] * b.value[0]) + (a.value[5] * b.value[4]) + (a.value[6] * b.value[8]) + (a.value[7] * b.value[12]);
	matXMat.value[5] = (a.value[4] * b.value[1]) + (a.value[5] * b.value[5]) + (a.value[6] * b.value[9]) + (a.value[7] * b.value[13]);
	matXMat.value[6] = (a.value[4] * b.value[2]) + (a.value[5] * b.value[6]) + (a.value[6] * b.value[10]) + (a.value[7] * b.value[14]);
	matXMat.value[7] = (a.value[4] * b.value[3]) + (a.value[5] * b.value[7]) + (a.value[6] * b.value[11]) + (a.value[7] * b.value[15]);

	matXMat.value[8] = (a.value[8] * b.value[0]) + (a.value[9] * b.value[4]) + (a.value[10] * b.value[8]) + (a.value[11] * b.value[12]);
	matXMat.value[9] = (a.value[8] * b.value[1]) + (a.value[9] * b.value[5]) + (a.value[10] * b.value[9]) + (a.value[11] * b.value[13]);
	matXMat.value[10] = (a.value[8] * b.value[2]) + (a.value[9] * b.value[6]) + (a.value[10] * b.value[10]) + (a.value[11] * b.value[14]);
	matXMat.value[11] = (a.value[8] * b.value[3]) + (a.value[9] * b.value[7]) + (a.value[10] * b.value[11]) + (a.value[11] * b.value[15]);

	matXMat.value[12] = (a.value[12] * b.value[0]) + (a.value[13] * b.value[4]) + (a.value[14] * b.value[8]) + (a.value[15] * b.value[12]);
	matXMat.value[13] = (a.value[12] * b.value[1]) + (a.value[13] * b.value[5]) + (a.value[14] * b.value[9]) + (a.value[15] * b.value[13]);
	matXMat.value[14] = (a.value[12] * b.value[2]) + (a.value[13] * b.value[6]) + (a.value[14] * b.value[10]) + (a.value[15] * b.value[14]);
	matXMat.value[15] = (a.value[12] * b.value[3]) + (a.value[13] * b.value[7]) + (a.value[14] * b.value[11]) + (a.value[15] * b.value[15]);
	return matXMat;
}

bool My::operator==(Matrix4x4 a, Matrix4x4 b)
{
	return (a.value[0] == b.value[0] && a.value[1] == b.value[1] && a.value[2] == b.value[2] && a.value[3] == b.value[3] &&
		a.value[4] == b.value[4] && a.value[5] == b.value[5] && a.value[6] == b.value[6] && a.value[7] == b.value[7] &&
		a.value[8] == b.value[8] && a.value[9] == b.value[9] && a.value[10] == b.value[10] && a.value[11] == b.value[11] &&
		a.value[12] == b.value[12] && a.value[13] == b.value[13] && a.value[14] == b.value[14] && a.value[15] == b.value[15]);
}

bool My::operator!=(Matrix4x4 a, Matrix4x4 b)
{
	return !(a == b);
}