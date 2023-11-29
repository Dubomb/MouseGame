#pragma once

#include <unordered_set>

#include "WorldEntity.h"

class World {
public:
	World();
	~World();

	template <class T>
	T* createEntity() {
		T* entity = new T();
		entities.insert(entity);
		return entity;
	}

	raylib::Color getBackgroundColor();
	void setBackgroundColor(raylib::Color backgroundColor);

	void updateWorld();

private:
	std::unordered_set<WorldEntity*> entities;

	raylib::Color backgroundColor;
};