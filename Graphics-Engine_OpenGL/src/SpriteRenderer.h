#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "Script.h"
#include "TextureImporter.h"

class SpriteRenderer : public Script {
public:
	Texture texture;

	void ImportTexture(const char* file_path, int type) {
		texture = TextureImporter::Import(file_path, type, texture);
	}

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

#endif // !SPRITERENDERER_H
