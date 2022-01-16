#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <list>
#include "BoxCollider.h"
#include "CircleCollider2D.h"
#include "GameObject.h"

class CollisionManager {
public:
	CollisionManager();

	void Insert(BoxCollider2D* component);
	void Insert(CircleCollider2D* component);

	void Remove(BoxCollider2D* component);
	void Remove(CircleCollider2D* component);

	void CheckCollisions();

private:
	std::vector<BoxCollider2D*> boxColliders;
	std::vector<CircleCollider2D*> circleColliders;
};

#endif // !COLLISIONMANAGER_H
