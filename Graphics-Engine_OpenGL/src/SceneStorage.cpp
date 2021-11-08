#include "SceneStorage.h"

void Scene_Storage::CreateScene(std::string name) {
	scenes[name] = Scene();
}

Scene Scene_Storage::GetScene(std::string name) {
	auto it = scenes.find(name);
	if (it != scenes.end())
		return it->second;
	else
		throw std::invalid_argument("Invalid Name Scene");
}