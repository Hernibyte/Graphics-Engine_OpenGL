#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "Script.h"
#include "TextureImporter.h"

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

	void ChangeAlpha(float alpha) {
		vertex[6] = alpha;
		vertex[15] = alpha;
		vertex[24] = alpha;
		vertex[33] = alpha;
	}

	void ChangeUV(float u, float v) {
		vertex[7] = u;
		vertex[16] = u;
		vertex[25] = u;
		vertex[34] = u;

		vertex[8] = v;
		vertex[17] = v;
		vertex[26] = v;
		vertex[35] = v;
	}
private:

};

#endif // !SPRITERENDERER_H
