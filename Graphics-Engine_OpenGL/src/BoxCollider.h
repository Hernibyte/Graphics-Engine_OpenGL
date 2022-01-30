#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "SpriteRenderer.h"

class BoxCollider2D : public Script {
public:
	BoxCollider2D() {
		center = { 0, 0, 0 };
		halfwidths = { 0.5f, 0.5f, 0.0f };
	}

	BoxCollider2D(Vector3 position, Vector3 scale) {
		center = position;
		halfwidths = scale;
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
