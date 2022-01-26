#ifndef SHAPERENDERER_H
#define SHAPERENDERER_H

#include "Script.h"

class ShapeRenderer : public Script {
public:
	float vertex[32] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f
	};
	unsigned int index[6] = {
		0, 1, 3,
		1, 2, 3
	};
};

#endif // !SHAPERENDERER_H
