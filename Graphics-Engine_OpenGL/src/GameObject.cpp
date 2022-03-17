#include "GameObject.h"

void GameObject::Name(std::string_view name) {
	this->name = name.data();
}

std::string* GameObject::Name() {
	return &name;
}