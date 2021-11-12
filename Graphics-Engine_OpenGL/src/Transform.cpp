#include "Transform.h"

Transform::Transform() {
	model = glm::mat4(1.0f);
	rotatex = glm::mat4(1.0f);
	rotatey = glm::mat4(1.0f);
	rotatez = glm::mat4(1.0f);
	scale = glm::mat4(1.0f);
	translate = glm::mat4(1.0f);

	position = glm::vec3();
	rotation = glm::quat();
	localScale = glm::vec3();
}

void Transform::UpdateModel() {
	model = translate * rotatex * rotatey * rotatez * scale;
}

void Transform::Rotate(float x, float y, float z) {
	RotateX(x);
	RotateY(y);
	RotateZ(z);
}

void Transform::Rotate(My::Quaternion quaternion) {
	RotateX(quaternion.x);
	RotateY(quaternion.y);
	RotateZ(quaternion.z);
}

void Transform::SetPosition(float x, float y, float z) {
	position[0] = x;
	position[1] = y;
	position[2] = z;

	translate = glm::translate(glm::mat4(1.0f), position);
	UpdateModel();
}

void Transform::SetPosition(My::Vector3 vector) {
	position[0] = vector.x;
	position[1] = vector.y;
	position[2] = vector.z;

	translate = glm::translate(glm::mat4(1.0f), position);
	UpdateModel();
}

void Transform::Translate(float x, float y, float z) {
	position[0] += x;
	position[1] += y;
	position[2] += z;

	translate = glm::translate(glm::mat4(1.0f), position);
	UpdateModel();
}

void Transform::Translate(My::Vector3 vector) {
	position[0] += vector.x;
	position[1] += vector.y;
	position[2] += vector.z;

	translate = glm::translate(glm::mat4(1.0f), position);
	UpdateModel();
}

void Transform::Scale(float x, float y, float z) {
	localScale[0] = x;
	localScale[1] = y;
	localScale[2] = z;

	scale = glm::scale(glm::mat4(1.0f), localScale);
	UpdateModel();
}

void Transform::RotateX(float x) {
	rotation[0] = x;
	glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
	axis[0] = 1.0f;
	axis[1] = 0.0f;
	axis[2] = 0.0f;

	rotatex = glm::rotate(glm::mat4(1.0f), x, axis);
	UpdateModel();
}

void Transform::RotateY(float y) {
	rotation[1] = y;
	glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
	axis[0] = 0.0f;
	axis[1] = 1.0f;
	axis[2] = 0.0f;

	rotatey = glm::rotate(glm::mat4(1.0f), y, axis);
	UpdateModel();
}

void Transform::RotateZ(float z) {
	rotation[2] = z;
	glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
	axis[0] = 0.0f;
	axis[1] = 0.0f;
	axis[2] = 1.0f;

	rotatez = glm::rotate(glm::mat4(1.0f), z, axis);
	UpdateModel();
}