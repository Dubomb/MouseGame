#include "WorldEntity.h"

WorldEntity::WorldEntity()
	: position(raylib::Vector2::Zero()), rotation(0.0f), parent(nullptr) {

}

WorldEntity::WorldEntity(const raylib::Vector2 position, const float rotation, WorldEntity* parent = nullptr) 
	: position(position), rotation(rotation), parent(parent) {

}

WorldEntity::~WorldEntity() {

}

void WorldEntity::setPosition(const raylib::Vector2 position) {
	for (WorldEntity* const child : children) {
		child->setPosition(child->getRelativePosition() + position);
	}

	this->position = position;
}

raylib::Vector2 WorldEntity::getPosition() {
	return this->position;
}

raylib::Vector2 WorldEntity::getRelativePosition() {
	return parent == nullptr ? this->position : this->position - parent->position;
}

void WorldEntity::translate(const raylib::Vector2 translation) {
	this->position += translation;

	for (WorldEntity* const child : children) {
		child->translate(translation);
	}
}

void WorldEntity::setRotation(const float rotation) {
	for (WorldEntity* const child : children) {
		child->setRotation(child->getRelativeRotation() + rotation);
	}

	this->rotation = rotation;
}

float WorldEntity::getRotation() {
	return this->rotation;
}

float WorldEntity::getRelativeRotation() {
	return parent == nullptr ? this->rotation : this->rotation - parent->rotation;
}

void WorldEntity::rotate(const float rotation) {
	this->rotation += rotation;

	for (WorldEntity* const child : children) {
		child->rotate(rotation);
	}
}

void WorldEntity::setParent(WorldEntity* const parent) {
	if (isChild(parent)) {
		return;
	}

	if (parent != nullptr) {
		parent->addChild(this);
	}

	if (this->parent != nullptr) {
		this->parent->removeChild(this);
	}

	this->parent = parent;
}

WorldEntity* WorldEntity::getParent() {
	return this->parent;
}

bool WorldEntity::isChild(WorldEntity* const child) {
	for (WorldEntity* const c : children) {
		if (children.count(c) != 0) {
			return true;
		}

		if (c->isChild(child)) {
			return true;
		}
	}

	return false;
}

void WorldEntity::addChild(WorldEntity* const child) {
	children.insert(child);
}

void WorldEntity::removeChild(WorldEntity* const child) {
	children.erase(child);
}
