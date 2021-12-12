#include "CollisionManager.h"

CollisionManager::CollisionManager() {
}

void CollisionManager::Insert(BoxCollider2D* component) {
	colliders.push_back(component);
}

void CollisionManager::Remove(BoxCollider2D* component) {
	colliders.remove(component);
}

void CollisionManager::CheckCollisions() {
	for (auto& firstCollider : colliders) {
		for (auto& secondCollider : colliders) {
			if ((firstCollider->Position().x - secondCollider->Position().x) < 
				(firstCollider->HalfWidths().x + secondCollider->HalfWidths().x) 
				&&
				(firstCollider->Position().y - secondCollider->Position().y) < 
				(firstCollider->HalfWidths().y + secondCollider->HalfWidths().y)) 
			{
				firstCollider->OnCollisionStay();
			}
		}
	}
}