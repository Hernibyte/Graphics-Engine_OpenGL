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

void Scene::AddObject() {
	Objects.push_back( new GameObject() );
	std::cout << Objects.size() << " - " <<
		Objects.capacity() << 
		std::endl;
}

GameObject* Scene::GetObject(int index) {
	return Objects.at(index);
}

std::vector<GameObject*> Scene::GetAllObjects() {
	return Objects;
}