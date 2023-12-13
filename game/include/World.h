#pragma once

#include <unordered_set>
#include <set>
#include <map>
#include <iostream>

#include "WorldEntity.h"

class World {
public:
	World();
	~World();

	template <class T>
	T* createEntity(const int layer) {
		T* entity = new T();
		entities.insert(std::make_pair(layer, entity));
		return entity;
	}

	raylib::Color getBackgroundColor();
	void setBackgroundColor(raylib::Color backgroundColor);

	void updateWorld();

private:
	std::multimap<int, WorldEntity*> entities;

	raylib::Color backgroundColor;
};