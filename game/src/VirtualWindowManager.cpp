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

bool VirtualWindowManager::createVirtualWindow(const std::string& name) {
	VirtualWindow* window = new VirtualWindow();

	windows[name] = window;
	draw_windows.insert(window);

	return true;
}

bool VirtualWindowManager::createVirtualWindow(const std::string& name, const raylib::Vector2 size, const raylib::Vector2 position, const int layer) {
	VirtualWindow* window = new VirtualWindow(size, position, layer);
	
	windows[name] = window;
	draw_windows.insert(window);

	return true;
}

VirtualWindow* VirtualWindowManager::getVirtualWindow(const std::string& name) {
	return windows[name];
}

void VirtualWindowManager::closeVirtualWindow(const std::string& name) {
	if (windows.count(name) != 1) {
		return;
	}

	draw_windows.erase(windows[name]);
	delete windows[name];
	windows.erase(name);
}

void VirtualWindowManager::drawWindowInteriors() {
	for (VirtualWindow* w : draw_windows) {
		w->draw_window_interior();
	}
}

void VirtualWindowManager::drawWindows() {
	for (VirtualWindow* w : draw_windows) {
		w->update();
	}
}