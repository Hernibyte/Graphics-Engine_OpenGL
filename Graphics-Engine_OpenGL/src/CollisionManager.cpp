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
			if (firstCollider != secondCollider) {
				float result_x = My::Abs((firstCollider->Position().x) - (secondCollider->Position().x));
				float result_y = My::Abs((firstCollider->Position().y) - (secondCollider->Position().y));

				if (result_x < (firstCollider->HalfWidths().x + secondCollider->HalfWidths().x) && 
					result_y < (firstCollider->HalfWidths().y + secondCollider->HalfWidths().y))
				{
					firstCollider->gameObject->OnCollisionStay();
				}
			}
		}
	}
}