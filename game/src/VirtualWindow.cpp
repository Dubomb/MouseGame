#include "VirtualWindow.h"
#include "TextureLibrary.h"

VirtualWindow::VirtualWindow() {
	setSize(MIN_SIZE);
	setPosition(raylib::Vector2::Zero());
	setLayer(0);
	TextureLibrary& textureLibrary = TextureLibrary::getInstance();
	this->windowTexture = textureLibrary.getTexture("window");
}

VirtualWindow::VirtualWindow(raylib::Vector2 size, raylib::Vector2 position, int layer) {
	setSize(size);
	setPosition(position);
	setLayer(layer);
	TextureLibrary& textureLibrary = TextureLibrary::getInstance();
	this->windowTexture = textureLibrary.getTexture("window");
}

VirtualWindow::~VirtualWindow() {

}

void VirtualWindow::setSize(raylib::Vector2 size) {
	this->size = size;

	if (size.x < MIN_SIZE.x) {
		this->size.x = MIN_SIZE.x;
	}

	if (size.y < MIN_SIZE.y) {
		this->size.y = MIN_SIZE.y;
	}

	interior = raylib::RenderTexture2D(size.x, size.y);
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

void VirtualWindow::setLayer(int layer) {
	this->layer = layer;
}

int VirtualWindow::getLayer() const {
	return this->layer;
}

void VirtualWindow::Draw() {
	interior.GetTexture().Draw(raylib::Vector2::Zero());
	windowTexture->Draw(NPATCH, raylib::Rectangle(position, size));
}

raylib::RenderTexture2D& VirtualWindow::getInterior() {
	return interior;
}

raylib::Camera2D& VirtualWindow::getCamera() {
	return camera;
}

const raylib::Vector2 VirtualWindow::MIN_SIZE = { 13, 21 };
const NPatchInfo VirtualWindow::NPATCH = { raylib::Rectangle(0, 0, 13, 21), 6, 12, 6, 8, NPATCH_NINE_PATCH };