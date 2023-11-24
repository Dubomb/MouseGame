#include "VirtualWindowManager.h"

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

	return true;
}

bool VirtualWindowManager::createVirtualWindow(std::string name, raylib::Vector2 size, raylib::Vector2 position) {
	VirtualWindow* window = new VirtualWindow(size, position);

	windows[name] = window;

	return true;
}

VirtualWindow* VirtualWindowManager::getVirtualWindow(std::string name) {
	return windows[name];
}

void VirtualWindowManager::closeVirtualWindow(std::string name) {
	delete windows[name];
	windows.erase(name);
}

void VirtualWindowManager::drawWindows() {
	for (const auto& pair : windows) {
		pair.second->Draw();
	}
}