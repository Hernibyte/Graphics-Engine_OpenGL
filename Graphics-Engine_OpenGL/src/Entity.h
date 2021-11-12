#ifndef ENTITY_H
#define ENTITY_H

#include "Transform.h"

class Entity {
public:
	Entity() = default;

	Transform transform = Transform();
};

#endif // !ENTITY_H
