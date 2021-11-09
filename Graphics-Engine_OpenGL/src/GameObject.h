#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Script.h"

class GameObject {
public:
	GameObject() = default;
	~GameObject() = default;
	
	void Awake(){
		for (auto& c : components)
			c->Awake();
	}

	void Start() {
		for (auto& c : components)
			c->Start();
	}

	void LateUpdate() {
		for (auto& c : components)
			c->LateUpdate();
	}

	void Update() {
		for (auto& c : components)
			c->Update();
	}

	void FixedUpdate() {
		for (auto& c : components)
			c->FixedUpdate();
	}

	template <typename T> 
	bool HasComponent() const {
		return componentBitSet[GetComponentTypeID<T>];
	}

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->gameObject = this;
		std::unique_ptr<Script> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[GetComponentTypeID<T>()] = c;
		componentBitSet[GetComponentTypeID<T>()] = true;

		return *c;
	}

	template <typename T>
	T& GetComponent() const {
		auto ptr(componentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

	template <typename T>
	bool TryGetComponent(T& outComponent) const {
		auto ptr(componentArray[GetComponentTypeID<T>()]);
		if (ptr != nullptr) {
			outComponent = *static_cast<T*>(ptr);
			return true;
		}
		else
			return false;
	}

private:
	std::vector<std::unique_ptr<Script>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
};

#endif // !GAMEOBJECT_H
