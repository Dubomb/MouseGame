#include "Screen.h"

#include <iostream>

void Screen::setVirtualScreenSize(const raylib::Vector2 size) {
	Screen::virtualScreenSize = size;
}

raylib::Vector2 Screen::getVirtualScreenSize() {
	return Screen::virtualScreenSize;
}

void Screen::setVirtualCamera(raylib::Camera2D* camera) {
	virtualCamera = camera;
}

raylib::Camera2D* Screen::getVirtualCamera() {
	return virtualCamera;
}

raylib::Vector2 Screen::getScreenSize() {
	return raylib::Vector2(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
}

raylib::Vector2 Screen::screenToVirtual(raylib::Vector2 position) {
	raylib::Vector2 result;
	raylib::Vector2 screenSize = getScreenSize();

	result.x = (position.x * virtualCamera->GetOffset().x * 2 / screenSize.x) - virtualCamera->GetOffset().x;
	result.y = ((screenSize.y - position.y) * virtualCamera->GetOffset().y * 2 / screenSize.y) - virtualCamera->GetOffset().y;
	result = result / virtualCamera->GetZoom() + virtualCamera->GetTarget();

	float radians = virtualCamera->GetRotation() * PI / 180;
	raylib::Vector2 rotationResult;
	rotationResult.x = result.x * std::cos(radians) - result.y * std::sin(radians);
	rotationResult.y = result.x * std::sin(radians) + result.y * std::cos(radians);
	return rotationResult;
}

raylib::Vector2 Screen::screenToWindowWorld(raylib::Vector2 position, VirtualWindow* window) {
	raylib::Vector2 result = position;
	raylib::Camera2D& camera = window->getCamera();
	raylib::Vector2 screenSize = getVirtualScreenSize();
	raylib::Vector2 textureSize = window->getInterior().GetTexture().GetSize();
	float screenToWorldRatio = camera.GetZoom();

	result.x -= window->getPosition().x;
	result.y += window->getPosition().y;
	result /= screenToWorldRatio;

	float radians = camera.GetRotation() * PI / 180;
	raylib::Vector2 rotationResult;
	rotationResult.x = result.x * std::cos(radians) + result.y * std::sin(radians);
	rotationResult.y = - result.x * std::sin(radians) + result.y * std::cos(radians);
	return rotationResult + camera.GetTarget();
}

raylib::Vector2 Screen::virtualScreenSize = { 1920, 1080 };
raylib::Camera2D* Screen::virtualCamera = nullptr;