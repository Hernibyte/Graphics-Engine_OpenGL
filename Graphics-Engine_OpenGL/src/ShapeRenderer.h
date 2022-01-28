#ifndef SHAPERENDERER_H
#define SHAPERENDERER_H

#include "Script.h"

class ShapeRenderer : public Script {
public:
	float vertex[36] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f
	};
	unsigned int index[6] = {
		0, 1, 3,
		1, 2, 3
	};

	void ChangeColor(float r, float g, float b) {
		vertex[3] = r;
		vertex[12] = r;
		vertex[21] = r;
		vertex[30] = r;

		vertex[4] = g;
		vertex[13] = g;
		vertex[22] = g;
		vertex[31] = g;

		vertex[5] = b;
		vertex[14] = b;
		vertex[23] = b;
		vertex[32] = b;
	}

	void ChangeColor(My::Vector3 rgb) {
		ChangeColor(rgb.x, rgb.y, rgb.z);
	}

	void ChangeAlpha(float alpha) {
		vertex[6] = alpha;
		vertex[15] = alpha;
		vertex[24] = alpha;
		vertex[33] = alpha;
	}
};

#endif // !SHAPERENDERER_H
