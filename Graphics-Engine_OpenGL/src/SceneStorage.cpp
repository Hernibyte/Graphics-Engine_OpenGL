#include "SceneStorage.h"

void Scene_Storage::CreateScene(std::string_view name) {
	scenes[name.data()] = Scene();
}

Scene* Scene_Storage::GetScene(std::string_view name) {
	auto it = scenes.find(name.data());
	if (it != scenes.end())
		return &it->second;
	else
		throw std::invalid_argument("Invalid Name Scene");
}