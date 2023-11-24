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

bool VirtualWindowManager::createVirtualWindow(std::string name) {
	VirtualWindow* window = new VirtualWindow();

	windows[name] = window;
	draw_windows.insert(window);

	return true;
}

bool VirtualWindowManager::createVirtualWindow(std::string name, raylib::Vector2 size, raylib::Vector2 position, int layer) {
	VirtualWindow* window = new VirtualWindow(size, position, layer);
	
	windows[name] = window;
	draw_windows.insert(window);

	return true;
}

VirtualWindow* VirtualWindowManager::getVirtualWindow(std::string name) {
	return windows[name];
}

void VirtualWindowManager::closeVirtualWindow(std::string name) {
	draw_windows.erase(windows[name]);
	delete windows[name];
	windows.erase(name);
}

void VirtualWindowManager::drawWindows() {
	for (VirtualWindow* w : draw_windows) {
		w->Draw();
	}
}