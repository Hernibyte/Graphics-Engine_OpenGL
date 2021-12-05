#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include "GameObject.h"
#include <iostream>
#include <string_view>

class Scene {
public:
	Scene();
	Scene(int maxGameObjects);
	~Scene();

	GameObject* AddObject();
	GameObject* GetObject(int index);
	std::vector<GameObject*> GetAllObjects();

	void Name(std::string_view name);
	std::string& Name();

private:
	std::string name;
	std::vector<GameObject*> Objects;
};

#endif // !SCENE_H
