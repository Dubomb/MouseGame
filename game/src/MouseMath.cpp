#include "MouseMath.h"

raylib::Vector2 MouseMath::rotatePoint(const raylib::Vector2 point, float angle) {
	float rad = angle * PI / 180;
	float x = point.x * cos(rad) - point.y * sin(rad);
	float y = point.x * sin(rad) + point.y * cos(rad);
	return raylib::Vector2(x, y);
}

bool MouseMath::pointInRect(const raylib::Vector2 p, const raylib::Rectangle rect, float angle) {
	raylib::Vector2 rotated = rotatePoint(p, -angle);
	return CheckCollisionPointRec(rotated, rect);
}

bool MouseMath::lineInRect(const raylib::Vector2 p1, const raylib::Vector2 p2, const raylib::Rectangle rect, float angle) {
	raylib::Vector2 r1 = { rect.x, rect.y };
	raylib::Vector2 r2 = { rect.x + rect.width, rect.y };
	raylib::Vector2 r3 = { rect.x + rect.width, rect.y + rect.height };
	raylib::Vector2 r4 = { rect.x, rect.y + rect.height };

	raylib::Vector2 d1 = rotatePoint(p1, -angle);
	raylib::Vector2 d2 = rotatePoint(p2, -angle);

	bool colliding = CheckCollisionLines(d1, d2, r1, r2, nullptr) ||
		CheckCollisionLines(d1, d2, r2, r3, nullptr) ||
		CheckCollisionLines(d1, d2, r3, r4, nullptr) ||
		CheckCollisionLines(d1, d2, r4, r1, nullptr);

	return colliding;
}
