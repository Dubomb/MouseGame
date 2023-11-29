#include "World.h"

World::World() 
	: backgroundColor(raylib::Color::Black()) {
	
}

World::~World() {
	for (WorldEntity* entity : entities) {
		delete entity;
	}
}

raylib::Color World::getBackgroundColor() {
	return backgroundColor;
}

void World::setBackgroundColor(raylib::Color backgroundColor) {
	this->backgroundColor = backgroundColor;
}

void World::updateWorld() {
	for (WorldEntity* entity : entities) {
		entity->update();
	}
}