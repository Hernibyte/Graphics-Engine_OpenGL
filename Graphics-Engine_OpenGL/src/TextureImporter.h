#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include "stb_image.h"
#include <iostream>

struct Texture {
	unsigned int texture;
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	int type;
};

class TextureImporter {
public:
	static Texture Import(const char* file_path, int type, Texture tex);
};

#endif // !TEXTUREIMPORTER_H
