#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "GameObject.h"
#include "TextureImporter.h"
#include "Animation.h"

class SpriteRenderer : public Script {
public:
	Texture texture;

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

	void ImportTexture(const char* file_path, int type) {
		texture = TextureImporter::Import(file_path, type, texture);
	}

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

	My::Vector3 Color() { 
		return 
			My::Vector3{ vertex[3], vertex[4], vertex[5] }; 
	}

	void ChangeAlpha(float alpha) {
		vertex[6] = alpha;
		vertex[15] = alpha;
		vertex[24] = alpha;
		vertex[33] = alpha;
	}

	float Alpha() { return vertex[6]; }

	void SetUVPoint1(float u, float v) {
		vertex[7] = u;
		vertex[8] = v;
	}

	void SetUVPoint2(float u, float v) {
		vertex[16] = u;
		vertex[17] = v;
	}

	void SetUVPoint3(float u, float v) {
		vertex[25] = u;
		vertex[26] = v;
	}

	void SetUVPoint4(float u, float v) {
		vertex[34] = u;
		vertex[35] = v;
	}
private:

};

#endif // !SPRITERENDERER_H
