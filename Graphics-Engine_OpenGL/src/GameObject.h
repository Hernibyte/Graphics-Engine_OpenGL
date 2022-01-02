#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Script.h"
#include "Entity.h"
#include "InputSystem.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID() {
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentID GetComponentTypeID() noexcept {
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Script*, maxComponents>;

class GameObject : public Entity {
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
		transform.Update();

		for (auto& c : components)
			c->Update();
	}

	void FixedUpdate() {
		for (auto& c : components)
			c->FixedUpdate();
	}

	void OnCollisionStay() {
		for (auto& c : components)
			c->OnCollisionStay();
	}

	template <typename T> 
	bool HasComponent() const {
		return componentBitSet[GetComponentTypeID<T>];
	}

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->gameObject = this;
		c->transform = &this->transform;
		c->Input = &this->Input;
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

	void Name(std::string_view name);
	std::string* Name();

private:
	std::vector<std::unique_ptr<Script>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

	InputSystem Input;

	std::string name;
};

#endif // !GAMEOBJECT_H
