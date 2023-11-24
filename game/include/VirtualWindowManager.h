#pragma once

#include <string>
#include <unordered_map>
#include <set>
#include <raylib.h>
#include <raylib-cpp.hpp>

#include "VirtualWindow.h"

class VirtualWindowManager {
public:
	VirtualWindowManager();
	~VirtualWindowManager();

	static VirtualWindowManager& getInstance();

	bool createVirtualWindow(std::string name);
	bool createVirtualWindow(std::string name, raylib::Vector2 size, raylib::Vector2 position, int layer);
	VirtualWindow* getVirtualWindow(std::string name);
	void closeVirtualWindow(std::string name);

	void drawWindows();

private:

	class VirtualWindowCompare {
	public:
		bool operator()(const VirtualWindow* lhs, const VirtualWindow* rhs) const {
			return lhs->getLayer() < rhs->getLayer();
		}
	};

	std::unordered_map<std::string, VirtualWindow*> windows;
	std::set<VirtualWindow*, VirtualWindowCompare> draw_windows;
};