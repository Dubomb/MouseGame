#include "World.h"

World::World() {

}

World::~World() {
	for (WorldEntity* entity : entities) {
		delete entity;
	}
}

void World::updateWorld() {
	for (WorldEntity* entity : entities) {
		entity->update();
	}
}