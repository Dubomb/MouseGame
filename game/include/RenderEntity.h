#pragma once

#include "WorldEntity.h"

class RenderEntity : public WorldEntity {
public:
	RenderEntity();
	RenderEntity(const raylib::Vector2 position, const float scale, const float rotation, WorldEntity* parent);
	~RenderEntity();

	void setScale(const raylib::Vector2 scale);
	raylib::Vector2 getScale();

	bool setSprite(const std::string& name);
	raylib::Texture2D* const getSprite();

	void setTint(const raylib::Color color);
	const raylib::Color& getTint();

	void update() override;

protected:
	raylib::Vector2 scale;
	raylib::Texture2D* sprite;
	raylib::Color tint;
};