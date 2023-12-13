#pragma once

#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <raylib.h>
#include <raylib-cpp.hpp>

#include "VirtualWindow.h"

class VirtualWindowManager {
public:
	VirtualWindowManager();
	~VirtualWindowManager();

	static VirtualWindowManager& getInstance();

	bool createVirtualWindow(const std::string& name, const raylib::Vector2 size, const raylib::Vector2 position, const int layer);
	VirtualWindow* getVirtualWindow(const std::string& name);
	void closeVirtualWindow(const std::string& name);

	void drawWindowInteriors();
	void drawWindows();

private:

	std::unordered_map<std::string, VirtualWindow*> windows;
	std::multimap<int, VirtualWindow*> drawingWindows;
};