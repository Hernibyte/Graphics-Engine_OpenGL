#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "Script.h"

class BoxCollider2D : public Script {
public:
	BoxCollider2D() {
		center = { 0, 0, 0 };
		halfwidths = { 0, 0, 0 };
	}

	BoxCollider2D(Vector3 position, Vector3 scale) {
		this->center = position;
		this->halfwidths = scale;
	}

	Vector3& Position() {
		return center;
	}
	Vector3& HalfWidths() {
		return halfwidths;
	}

private:
	Vector3 center;
	Vector3 halfwidths;
};

#endif // !BOXCOLLIDER_H
