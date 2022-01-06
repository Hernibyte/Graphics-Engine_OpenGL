#include "CollisionManager.h"

CollisionManager::CollisionManager() {
}

void CollisionManager::Insert(BoxCollider2D* component) {
	boxColliders.push_back(component);
}

void CollisionManager::Insert(CircleCollider2D* component) {
	circleColliders.push_back(component);
}

void CollisionManager::Remove(BoxCollider2D* component) {
	boxColliders.remove(component);
}

void CollisionManager::Remove(CircleCollider2D* component) {
	circleColliders.remove(component);
}

void CollisionManager::CheckCollisions() {
	for (auto& a : boxColliders) {
		for (auto& secondCollider : boxColliders) {
			if (a != secondCollider) {
				float result_x = My::Abs((a->Position().x) - (secondCollider->Position().x));
				float result_y = My::Abs((a->Position().y) - (secondCollider->Position().y));

				if (result_x < (a->HalfWidths().x + secondCollider->HalfWidths().x) && 
					result_y < (a->HalfWidths().y + secondCollider->HalfWidths().y))
				{
					a->gameObject->OnCollisionStay();
				}
			}
		}

		for (auto& b : circleColliders) {
			My::Vector3 p = My::Vector3{};
			p = b->Position();

			if (p.x < a->Position().x - a->HalfWidths().x) p.x = a->Position().x - a->HalfWidths().x;
			if (p.x > a->Position().x + a->HalfWidths().x) p.x = a->Position().x + a->HalfWidths().x;

			if (p.y < a->Position().y - a->HalfWidths().y) p.y = a->Position().y - a->HalfWidths().y;
			if (p.y > a->Position().y + a->HalfWidths().y) p.y = a->Position().y + a->HalfWidths().y;

			float result = My::Sqrt(
				My::Pow((b->Position().x - p.x), 2) + My::Pow((b->Position().y - p.y), 2)
			);

			if (result < b->Radius()) {
				a->gameObject->OnCollisionStay();
			}
		}
	}

	for (auto& a : circleColliders) {
		for (auto& b : circleColliders) {
			if (a != b) {
				float result = My::Sqrt(
					My::Pow((a->Position().x - b->Position().x), 2) +
					My::Pow((a->Position().y - b->Position().y), 2));

				if (result < (a->Radius() + b->Radius())) {
					a->gameObject->OnCollisionStay();
				}
			}
		}

		for (auto& b : boxColliders) {
			My::Vector3 p = My::Vector3{};
			p = a->Position();

			if (p.x < b->Position().x - b->HalfWidths().x) p.x = b->Position().x - b->HalfWidths().x;
			if (p.x > b->Position().x + b->HalfWidths().x) p.x = b->Position().x + b->HalfWidths().x;

			if (p.y < b->Position().y - b->HalfWidths().y) p.y = b->Position().y - b->HalfWidths().y;
			if (p.y > b->Position().y + b->HalfWidths().y) p.y = b->Position().y + b->HalfWidths().y;

			float result = My::Sqrt(
				My::Pow((a->Position().x - p.x), 2) + My::Pow((a->Position().y - p.y), 2)
			);

			if (result < a->Radius()) {
				a->gameObject->OnCollisionStay();
			}
		}
	}
}