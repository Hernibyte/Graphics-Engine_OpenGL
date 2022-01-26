#include "TextureImporter.h"

Texture TextureImporter::Import(const char* file_path, int type, Texture tex) {
	Texture aux;

	stbi_set_flip_vertically_on_load(true);

	aux.data = stbi_load(file_path, &tex.width, &tex.height, &tex.nrChannels, 0);
	aux.type = type;

	return aux;
}
