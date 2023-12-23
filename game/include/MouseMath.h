#pragma once

#include <raylib.h>
#include <raylib-cpp.hpp>

class MouseMath {
public:
	static raylib::Vector2 rotatePoint(const raylib::Vector2 point, float angle);

	static bool pointInRect(const raylib::Vector2 p, const raylib::Rectangle rect, float angle);
	static bool lineInRect(const raylib::Vector2 p1, const raylib::Vector2 p2, const raylib::Rectangle rect, float angle);
};