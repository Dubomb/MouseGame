#include <iostream>
#include<raylib.h>
#include <raylib-cpp.hpp>

int main(void) {

	int width = 800;
	int height = 600;
	raylib::Color text = raylib::Color::Black();
	raylib::Window window(width, height, "raylib!", FLAG_VSYNC_HINT);

	raylib::Vector2 ballPos = { -100.0f, -100.0f };
	raylib::Color ballColor = raylib::Color::DarkBlue();
	raylib::Color innerBallColor = raylib::Color::RayWhite();

	const int radius = 50;
	const int innerRadius = 40;

	while (!window.ShouldClose()) {

		ballPos = GetMousePosition();

		ballColor = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? raylib::Color::Red() : raylib::Color::DarkBlue();

		BeginDrawing();
		window.ClearBackground(raylib::Color::RayWhite());
		ballPos.DrawCircle(radius, ballColor);
		ballPos.DrawCircle(innerRadius, innerBallColor);
		text.DrawText(TextFormat("x: %f, y: %f", ballPos.x, ballPos.y), 10, 10, 20);
		EndDrawing();
	}

	return 0;
}