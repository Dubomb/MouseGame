#pragma once

#include <raylib.h>
#include <raylib-cpp.hpp>

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

	int layer;
};