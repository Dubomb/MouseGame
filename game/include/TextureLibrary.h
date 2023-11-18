#pragma once

#include <string>
#include <unordered_map>

#include <raylib.h>
#include <raylib-cpp.hpp>

class TextureLibrary {
public:
	TextureLibrary();
	~TextureLibrary();

	static TextureLibrary& getInstance();
	
	bool loadTexture(std::string path, std::string name);
	raylib::Texture2D* getTexture(std::string name);

private:
	std::unordered_map<std::string, raylib::Texture2D*> textures;
};
