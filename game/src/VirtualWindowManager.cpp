#include "VirtualWindowManager.h"

#include <iostream>

VirtualWindowManager::VirtualWindowManager() {

}

VirtualWindowManager::~VirtualWindowManager() {
	for (const auto& pair : windows) {
		delete pair.second;
	}
}

VirtualWindowManager& VirtualWindowManager::getInstance() {
	static VirtualWindowManager instance;
	return instance;
}

bool VirtualWindowManager::createVirtualWindow(const std::string& name, const raylib::Vector2 size, const raylib::Vector2 position, const int layer) {
	VirtualWindow* window = new VirtualWindow(size, position);
	
	windows[name] = window;
	drawingWindows.insert(std::make_pair(layer, window));

	return true;
}

VirtualWindow* VirtualWindowManager::getVirtualWindow(const std::string& name) {
	return windows[name];
}

void VirtualWindowManager::closeVirtualWindow(const std::string& name) {
	if (windows.count(name) != 1) {
		return;
	}

	VirtualWindow* window = windows[name];

	for (auto it = drawingWindows.begin(); it != drawingWindows.end(); it++) {
		if (it->second == window) {
			drawingWindows.erase(it);
			break;
		}
	}

	delete windows[name];
	windows.erase(name);
}

void VirtualWindowManager::drawWindowInteriors() {
	for (auto pair : drawingWindows) {
		pair.second->draw_window_interior();
	}
}

void VirtualWindowManager::drawWindows() {
	for (auto pair : drawingWindows) {
		pair.second->update();
	}
}