#pragma once

#include <unordered_set>
#include <raylib.h>
#include <raylib-cpp.hpp>

class WorldEntity {
public:
	WorldEntity();
	WorldEntity(const raylib::Vector2 position, const float rotation, WorldEntity* parent);
	~WorldEntity();

	void setPosition(const raylib::Vector2 position);
	raylib::Vector2 getPosition();
	raylib::Vector2 getRelativePosition();
	void translate(const raylib::Vector2 translation);

	void setRotation(const float rotation);
	float getRotation();
	float getRelativeRotation();
	void rotate(const float rotation);

	void setParent(WorldEntity* const parent);
	WorldEntity* getParent();
	bool isChild(WorldEntity* const child);

private:
	void addChild(WorldEntity* const child);
	void removeChild(WorldEntity* const child);

	WorldEntity* parent;
	std::unordered_set<WorldEntity*> children;

protected:
	raylib::Vector2 position;
	float rotation;
};