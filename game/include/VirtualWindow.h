#pragma once

#include <raylib.h>
#include <raylib-cpp.hpp>

#include "World.h"

class VirtualWindow {
public:
	VirtualWindow();
	VirtualWindow(raylib::Vector2 size, raylib::Vector2 position, int layer);
	~VirtualWindow();

	void setSize(raylib::Vector2 size);
	raylib::Vector2 getSize() const;
	void setPosition(raylib::Vector2 position);
	raylib::Vector2 getPosition() const;
	void setLayer(int layer);
	int getLayer() const;

	void setWorld(World* const world);
	World* getWorld();

	void setCameraOffset(raylib::Vector2 offset);
	raylib::Vector2 getCameraOffset();
	void setCameraTarget(raylib::Vector2 target);
	raylib::Vector2 getCameraTarget();
	void setCameraRotation(float rotation);
	float getCameraRotation();
	void setCameraZoom(float zoom);
	float getCameraZoom();

	void draw_window_interior();
	void update();

	raylib::RenderTexture2D& getInterior();
	raylib::Camera2D& getCamera();

private:
	const static raylib::Vector2 MIN_SIZE;
	const static raylib::Vector2 TOP_LEFT;
	const static raylib::Vector2 BOT_RIGHT;
	const static NPatchInfo NPATCH;

	raylib::Vector2 position;
	raylib::Vector2 size;
	raylib::Texture* windowTexture;
	
	raylib::RenderTexture2D interior;
	raylib::Camera2D camera;

	int layer;

	World* world;
};