#include "VirtualWindow.h"
#include "TextureLibrary.h"

VirtualWindow::VirtualWindow() {
	setSize(MIN_SIZE);
	setPosition(raylib::Vector2::Zero());
	TextureLibrary& textureLibrary = TextureLibrary::getInstance();
	this->windowTexture = textureLibrary.getTexture("window");
	this->interior = raylib::RenderTexture2D();
	setCameraTarget(raylib::Vector2(0, 0));
	setCameraRotation(0.0f);
	setCameraZoom(1.0f);
	setWorld(nullptr);
}

VirtualWindow::VirtualWindow(raylib::Vector2 size, raylib::Vector2 position) {
	setSize(size);
	setPosition(position);
	TextureLibrary& textureLibrary = TextureLibrary::getInstance();
	this->windowTexture = textureLibrary.getTexture("window");
	setCameraTarget(raylib::Vector2(0, 0));
	setCameraRotation(0.0f);
	setCameraZoom(1.0f);
	setWorld(nullptr);
}

VirtualWindow::~VirtualWindow() {

}

void VirtualWindow::setSize(raylib::Vector2 size) {
	if (size.x < MIN_SIZE.x) {
		size.x = MIN_SIZE.x;
	}

	if (size.y < MIN_SIZE.y) {
		size.y = MIN_SIZE.y;
	}

	interior = raylib::RenderTexture2D(size.x, size.y);
	this->size.x = size.x + TOP_LEFT.x + BOT_RIGHT.x;
	this->size.y = size.y + TOP_LEFT.y + BOT_RIGHT.y;
}

raylib::Vector2 VirtualWindow::getSize() const {
	return this->size;
}

void VirtualWindow::setPosition(raylib::Vector2 position) {
	this->position = position;
}

raylib::Vector2 VirtualWindow::getPosition() const {
	return this->position;
}

void VirtualWindow::setWorld(World* const world) {
	this->world = world;
}

World* VirtualWindow::getWorld() {
	return world;
}

void VirtualWindow::setCameraOffset(raylib::Vector2 offset) {
	camera.SetOffset(offset);
}

raylib::Vector2 VirtualWindow::getCameraOffset() {
	return camera.GetOffset();
}

void VirtualWindow::setCameraTarget(raylib::Vector2 target) {
	camera.SetTarget(target);
}

raylib::Vector2 VirtualWindow::getCameraTarget() {
	return camera.GetTarget();
}

void VirtualWindow::setCameraRotation(float rotation) {
	camera.SetRotation(rotation);
}

float VirtualWindow::getCameraRotation() {
	return camera.GetRotation();
}

void VirtualWindow::setCameraZoom(float zoom) {
	camera.SetZoom(zoom);
}

float VirtualWindow::getCameraZoom() {
	return camera.GetZoom();
}

void VirtualWindow::draw_window_interior() {
	setCameraOffset(raylib::Vector2(interior.GetTexture().GetSize()) * 0.5f);

	BeginTextureMode(interior);

	BeginMode2D(camera);
	
	ClearBackground(world->getBackgroundColor());

	if (world != nullptr) {
		world->updateWorld();
	}

	EndMode2D();
	
	EndTextureMode();
}

void VirtualWindow::update() {
	interior.GetTexture().Draw(position + TOP_LEFT - size * 0.5f);
	windowTexture->Draw(NPATCH, raylib::Rectangle(position - size * 0.5f, size));
}

raylib::RenderTexture2D& VirtualWindow::getInterior() {
	return interior;
}

raylib::Camera2D& VirtualWindow::getCamera() {
	return camera;
}

const raylib::Vector2 VirtualWindow::MIN_SIZE = { 13, 25 };
const raylib::Vector2 VirtualWindow::TOP_LEFT = { 6, 16 };
const raylib::Vector2 VirtualWindow::BOT_RIGHT = { 6, 8 };
const NPatchInfo VirtualWindow::NPATCH = { raylib::Rectangle(raylib::Vector2::Zero(), VirtualWindow::MIN_SIZE), TOP_LEFT.x, TOP_LEFT.y, BOT_RIGHT.x, BOT_RIGHT.y, NPATCH_NINE_PATCH };