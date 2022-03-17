#include "Scene.h"

Scene::Scene() {
	Objects.reserve(1500);
}

Scene::Scene(int maxGameObjects) {
	Objects.reserve(maxGameObjects);
}

Scene::~Scene() {
	for (int i = 0; i < Objects.size(); i++) {
		if(Objects[i] != nullptr)
			delete Objects[i];
	}
}

GameObject* Scene::AddObject() {
	Objects.push_back( new GameObject() );
	return Objects.back();
}

GameObject* Scene::GetObject(int index) {
	return Objects.at(index);
}

std::vector<GameObject*> Scene::GetAllObjects() {
	return Objects;
}

void Scene::Name(std::string_view name) {
	this->name = name.data();
}

std::string& Scene::Name() {
	return name;
}