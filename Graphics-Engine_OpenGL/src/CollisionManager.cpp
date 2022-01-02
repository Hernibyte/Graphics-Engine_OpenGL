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
				float result_x = Vector3::Distance(	Vector3{ firstCollider->Position().x, 0, 0	},
													Vector3{ secondCollider->Position().x, 0, 0 });
				float result_y = Vector3::Distance(	Vector3{ 0, firstCollider->Position().y, 0 },
													Vector3{ 0, secondCollider->Position().y, 0 });

				if (result_x < (firstCollider->HalfWidths().x + secondCollider->HalfWidths().x) && 
					result_y < (firstCollider->HalfWidths().y + secondCollider->HalfWidths().y))
				{
					firstCollider->gameObject->OnCollisionStay();
				}
			}
		}
	}
}