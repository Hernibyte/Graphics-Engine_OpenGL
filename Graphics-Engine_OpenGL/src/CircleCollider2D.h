#ifndef CIRCLECOLLIDER2D_H
#define CIRCLECOLLIDER2D_H

#include "Script.h"

class CircleCollider2D : public Script {
public:
	
	CircleCollider2D() {
		_center = My::Vector3{ 0, 0, 0 };
		_radius = 0.5f;
	}

	CircleCollider2D(My::Vector3 center, float radius) {
		_center = center;
		_radius = radius;
	}

	My::Vector3& Position() {
		return _center;
	}

	float& Radius() {
		return _radius;
	}

private:
	My::Vector3 _center;
	float _radius;
};

#endif // !CIRCLECOLLIDER2D_H
