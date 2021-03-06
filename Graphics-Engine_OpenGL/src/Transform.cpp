#include "Transform.h"

Transform::Transform() {
	model = glm::mat4(1.0f);
	rotatex = glm::mat4(1.0f);
	rotatey = glm::mat4(1.0f);
	rotatez = glm::mat4(1.0f);
	scale = glm::mat4(1.0f);
	translate = glm::mat4(1.0f);

	myposition = glm::vec3();
	myrotation = glm::quat();
	mylocalScale = glm::vec3();
}

void Transform::UpdateModel() {
	model = translate * rotatex * rotatey * rotatez * scale;
}

glm::mat4 Transform::Model() const {
	return model;
}

void Transform::Update() {
	if (myposition.x != position.x
	|| myposition.y != position.y
	|| myposition.z != position.z) {
		SetPosition(position);
	}

	if (myrotation.x != rotation.x
	|| myrotation.y != rotation.y
	|| myrotation.z != rotation.z
	|| myrotation.w != rotation.w) {
		Rotate(rotation);
	}

	if (mylocalScale.x != localScale.x
	|| mylocalScale.y != localScale.y
	|| mylocalScale.z != localScale.z) {
		Scale(localScale.x, localScale.y, localScale.z);
	}
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
	myposition[0] = x;
	myposition[1] = y;
	myposition[2] = z;

	position.x = x;
	position.y = y;
	position.z = z;

	translate = glm::translate(glm::mat4(1.0f), myposition);
	UpdateModel();
}

void Transform::SetPosition(My::Vector3 vector) {
	myposition[0] = vector.x;
	myposition[1] = vector.y;
	myposition[2] = vector.z;

	position.x = vector.x;
	position.y = vector.y;
	position.z = vector.z;

	translate = glm::translate(glm::mat4(1.0f), myposition);
	UpdateModel();
}

void Transform::Translate(float x, float y, float z) {
	myposition[0] += x;
	myposition[1] += y;
	myposition[2] += z;

	position.x += x;
	position.y += y;
	position.z += z;

	translate = glm::translate(glm::mat4(1.0f), myposition);
	UpdateModel();
}

void Transform::Translate(My::Vector3 vector) {
	myposition[0] += vector.x;
	myposition[1] += vector.y;
	myposition[2] += vector.z;

	position.x += vector.x;
	position.y += vector.y;
	position.z += vector.z;

	translate = glm::translate(glm::mat4(1.0f), myposition);
	UpdateModel();
}

void Transform::Scale(float x, float y, float z) {
	mylocalScale[0] = x;
	mylocalScale[1] = y;
	mylocalScale[2] = z;

	localScale.x = x;
	localScale.y = y;
	localScale.z = z;

	scale = glm::scale(glm::mat4(1.0f), mylocalScale);
	UpdateModel();
}

void Transform::RotateX(float x) {
	myrotation[0] = x;
	glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
	axis[0] = 1.0f;
	axis[1] = 0.0f;
	axis[2] = 0.0f;

	rotation.x = x;

	rotatex = glm::rotate(glm::mat4(1.0f), x, axis);
	UpdateModel();
}

void Transform::RotateY(float y) {
	myrotation[1] = y;
	glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
	axis[0] = 0.0f;
	axis[1] = 1.0f;
	axis[2] = 0.0f;

	rotation.y = y;

	rotatey = glm::rotate(glm::mat4(1.0f), y, axis);
	UpdateModel();
}

void Transform::RotateZ(float z) {
	myrotation[2] = z;
	glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
	axis[0] = 0.0f;
	axis[1] = 0.0f;
	axis[2] = 1.0f;

	rotation.z = z;

	rotatez = glm::rotate(glm::mat4(1.0f), z, axis);
	UpdateModel();
}