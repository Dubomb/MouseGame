#include "World.h"

World::World() 
	: backgroundColor(raylib::Color::Black()) {
	
}

World::~World() {
	for (auto pair : entities) {
		delete pair.second;
	}
}

raylib::Color World::getBackgroundColor() {
	return backgroundColor;
}

void World::setBackgroundColor(raylib::Color backgroundColor) {
	this->backgroundColor = backgroundColor;
}

void World::updateWorld() {
	for (auto pair : entities) {
		pair.second->update();
	}
}