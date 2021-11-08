#ifndef SCENESTORAGE_H
#define SCENESTORAGE_H

#include "Scene.h"
#include <stdexcept>

class ENGINE_API Scene_Storage {
public:
	Scene_Storage() = default;

	Scene_Storage(const Scene_Storage&) = delete;
	Scene_Storage(Scene_Storage&&) = delete;
	Scene_Storage* operator=(const Scene_Storage&) = delete;
	Scene_Storage* operator=(Scene_Storage&&) = delete;

	void CreateScene(std::string name);
	Scene GetScene(std::string name);

private:
	std::unordered_map<std::string, Scene> scenes;
};

#endif // !SCENESTORAGE_H
