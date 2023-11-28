#include "RenderEntity.h"
#include "TextureLibrary.h"

RenderEntity::RenderEntity() 
	: WorldEntity(), scale(raylib::Vector2::One()), sprite(nullptr), tint(raylib::Color::White()) {
	
}

RenderEntity::RenderEntity(const raylib::Vector2 position, const float scale, const float rotation, WorldEntity* parent) 
	: WorldEntity(position, rotation, parent), scale(scale), sprite(nullptr), tint(raylib::Color::White()) {

}

RenderEntity::~RenderEntity() {

}

void RenderEntity::setScale(const raylib::Vector2 scale) {
	this->scale = scale;
}

raylib::Vector2 RenderEntity::getScale() {
	return this->scale;
}

bool RenderEntity::setSprite(const std::string& name) {
	raylib::Texture2D* texture;
	TextureLibrary& lib = TextureLibrary::getInstance();
	texture = lib.getTexture(name);

	if (texture == nullptr) {
		return false;
	}

	sprite = texture;

	return true;
}

raylib::Texture2D* const RenderEntity::getSprite() {
	return sprite;
}

void RenderEntity::setTint(const raylib::Color color) {
	tint = color;
}

const raylib::Color& RenderEntity::getTint() {
	return tint;
}

#include <iostream>

void RenderEntity::Draw() {
	raylib::Vector2 textureSize = sprite->GetSize();

	raylib::Rectangle src(raylib::Vector2::Zero(), textureSize);

	textureSize = raylib::Vector2(textureSize.x * scale.x, textureSize.y * scale.y);
	raylib::Vector2 center = raylib::Vector2(textureSize.x * 0.5f, textureSize.y * 0.5f);
	raylib::Rectangle dest(position, textureSize);

	std::cout << "x: " << dest.x << " y: " << dest.y << " w: " << dest.width << " h: " << dest.height << std::endl;

	sprite->Draw(src, dest, center, rotation, tint);
}