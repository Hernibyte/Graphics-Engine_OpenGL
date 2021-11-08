#ifndef SCENESTORAGE_H
#define SCENESTORAGE_H

#include "Scene.h"
#include <stdexcept>

class Scene_Storage {
public:
	void CreateScene(std::string name);
	Scene GetScene(std::string name);

private:
	std::unordered_map<std::string, Scene> scenes;
};

#endif // !SCENESTORAGE_H
