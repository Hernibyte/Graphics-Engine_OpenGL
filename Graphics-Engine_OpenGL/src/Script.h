#ifndef SCRIPT_H
#define SCRIPT_H

#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Script;
class GameObject;

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

class Script {
public:
	GameObject* gameObject = nullptr;

	virtual void Awake() {}
	virtual void Start() {}
	virtual void LateUpdate() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}

	virtual ~Script() {}
};

#endif // !SCRIPT_H
