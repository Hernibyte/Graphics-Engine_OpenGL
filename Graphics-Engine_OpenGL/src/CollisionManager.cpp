#include "CollisionManager.h"

CollisionManager::CollisionManager() {
	boxColliders.reserve(1500);
	circleColliders.reserve(1500);
}

void CollisionManager::Insert(BoxCollider2D* component) {
	boxColliders.push_back(component);
}

void CollisionManager::Insert(CircleCollider2D* component) {
	circleColliders.push_back(component);
}

void CollisionManager::Remove(BoxCollider2D* component) {
	using Iter = std::vector<BoxCollider2D*>::iterator;
	for (Iter iter = boxColliders.begin(); iter != boxColliders.end(); iter++)
		if (*iter == component) boxColliders.erase(iter);
}

void CollisionManager::Remove(CircleCollider2D* component) {
	using Iter = std::vector<CircleCollider2D*>::iterator;
	for (Iter iter = circleColliders.begin(); iter != circleColliders.end(); iter++)
		if (*iter == component) circleColliders.erase(iter);
}

void CollisionManager::CheckCollisions() {
	using BoxIter = std::vector<BoxCollider2D*>::iterator;
	using CircleIter = std::vector<CircleCollider2D*>::iterator;

	int initPos = 1;
	for (BoxIter first = boxColliders.begin(); first != boxColliders.end(); first++) {
		BoxCollider2D* a = *first;
		for (BoxIter second = boxColliders.begin() + initPos; second != boxColliders.end(); second++) {
			BoxCollider2D* b = *second;

			float result_x = My::Abs((a->Position().x) - (b->Position().x));
			float result_y = My::Abs((a->Position().y) - (b->Position().y));

			if (result_x < (a->HalfWidths().x + b->HalfWidths().x) &&
				result_y < (a->HalfWidths().y + b->HalfWidths().y))
			{
				a->gameObject->OnCollisionStay();
				b->gameObject->OnCollisionStay();
			}
		}

		for (CircleIter second = circleColliders.begin(); second != circleColliders.end(); second++) {
			CircleCollider2D* b = *second;

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
				b->gameObject->OnCollisionStay();
			}
		}

		initPos++;
	}

	initPos = 1;
	for (CircleIter first = circleColliders.begin(); first != circleColliders.end(); first++) {
		CircleCollider2D* a = *first;
		for (CircleIter second = circleColliders.begin() + initPos; second != circleColliders.end(); second++) {
			CircleCollider2D* b = *second;

			float result = My::Sqrt(
				My::Pow((a->Position().x - b->Position().x), 2) +
				My::Pow((a->Position().y - b->Position().y), 2));
	
			if (result < (a->Radius() + b->Radius())) {
				a->gameObject->OnCollisionStay();
				b->gameObject->OnCollisionStay();
			}
		}
	}
}