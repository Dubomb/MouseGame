#pragma once

#include <string>
#include <map>
#include <raylib.h>
#include <raylib-cpp.hpp>

#include "VirtualWindow.h"

class VirtualWindowManager {
public:
	VirtualWindowManager();
	~VirtualWindowManager();

	static VirtualWindowManager& getInstance();

	bool createVirtualWindow(std::string name);
	bool createVirtualWindow(std::string name, raylib::Vector2 size, raylib::Vector2 position);
	VirtualWindow* getVirtualWindow(std::string name);
	void closeVirtualWindow(std::string name);

	void drawWindows();

private:
	std::map<std::string, VirtualWindow*> windows;
};