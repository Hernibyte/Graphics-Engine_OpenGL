#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <list>
#include "BoxCollider.h"
#include "GameObject.h"

class CollisionManager {
public:
	CollisionManager();

	void Insert(BoxCollider2D* component);

	void Remove(BoxCollider2D* component);

	void CheckCollisions();

private:
	std::list<BoxCollider2D*> colliders;
};

#endif // !COLLISIONMANAGER_H
