#pragma once

#include <raylib.h>
#include <raylib-cpp.hpp>

#include "VirtualWindow.h"

class Screen {
public:

	static void setVirtualScreenSize(const raylib::Vector2 size);
	static raylib::Vector2 getVirtualScreenSize();
	static void setVirtualCamera(raylib::Camera2D* camera);
	static raylib::Camera2D* getVirtualCamera();


	static raylib::Vector2 getScreenSize();
	static raylib::Vector2 screenToVirtual(raylib::Vector2 position);
	static raylib::Vector2 screenToWindowWorld(raylib::Vector2 position, VirtualWindow* window);

private:
	static raylib::Vector2 virtualScreenSize;
	static raylib::Camera2D* virtualCamera;
};