#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/glm/matrix.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include "MyMath/My.h"

struct Transform {
private:
	void RotateX(float x);
	void RotateY(float y);
	void RotateZ(float z);
public:
	Transform();

	glm::mat4 model;
	glm::mat4 translate;
	glm::mat4 rotatex;
	glm::mat4 rotatey;
	glm::mat4 rotatez;
	glm::mat4 scale;

	void UpdateModel();

	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 localScale;

	void Rotate(float x, float y, float z);
	void Rotate(My::Quaternion quaternion);
	void SetPosition(float x, float y, float z);
	void SetPosition(My::Vector3 vector);
	void Translate(float x, float y, float z);
	void Translate(My::Vector3 vector);
	void Scale(float x, float y, float z);
};

#endif // !TRANSFORM_H
