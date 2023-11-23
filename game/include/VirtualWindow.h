#pragma once

#include <raylib.h>
#include <raylib-cpp.hpp>

class VirtualWindow {
public:
	VirtualWindow();
	VirtualWindow(raylib::Vector2 size, raylib::Vector2 position);
	~VirtualWindow();

	void setSize(raylib::Vector2 size);
	raylib::Vector2 getSize();
	void setPosition(raylib::Vector2 position);
	raylib::Vector2 getPosition();
	void Draw();

	raylib::RenderTexture2D& getInterior();
	raylib::Camera2D& getCamera();

private:
	const static raylib::Vector2 MIN_SIZE;
	const static NPatchInfo NPATCH;

	raylib::Vector2 position;
	raylib::Vector2 size;
	raylib::Texture* windowTexture;
	
	raylib::RenderTexture2D interior;
	raylib::Camera2D camera;
};