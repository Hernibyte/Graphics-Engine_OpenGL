#ifndef SCENESTORAGE_H
#define SCENESTORAGE_H

#include "Scene.h"
#include <stdexcept>

class Scene_Storage {
public:
	Scene_Storage() = default;

	Scene_Storage(const Scene_Storage&) = delete;
	Scene_Storage(Scene_Storage&&) = delete;
	Scene_Storage* operator=(const Scene_Storage&) = delete;
	Scene_Storage* operator=(Scene_Storage&&) = delete;

	Scene* CreateScene(std::string_view name);
	Scene* GetScene(std::string_view name);

private:
	std::unordered_map<std::string, Scene> scenes;
};

#endif // !SCENESTORAGE_H
