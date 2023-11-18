#pragma once

#include <string>
#include <unordered_map>

#include <raylib.h>
#include <raylib-cpp.hpp>

class FontLibrary {
public:
	FontLibrary();
	~FontLibrary();

	static FontLibrary& getInstance();

	bool loadFont(std::string path, std::string name);
	raylib::Font* getFont(std::string name);

private:
	std::unordered_map<std::string, raylib::Font*> fonts;
};