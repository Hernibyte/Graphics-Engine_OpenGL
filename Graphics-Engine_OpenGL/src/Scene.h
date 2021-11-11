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

	void AddObject();
	GameObject* GetObject(int index);
	std::vector<GameObject*> GetAllObjects();

private:
	std::vector<GameObject*> Objects;
};

#endif // !SCENE_H
