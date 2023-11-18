#include "TextureLibrary.h"
#include <iostream>

TextureLibrary::TextureLibrary() {

}

TextureLibrary::~TextureLibrary() {
	for (const auto& pair : textures) {
		delete pair.second;
		std::cout << "deleted!" << std::endl;
	}
}

TextureLibrary& TextureLibrary::getInstance() {
	static TextureLibrary instance;
	return instance;
}

bool TextureLibrary::loadTexture(std::string path, std::string name) {
	raylib::Texture2D* texture = new raylib::Texture2D(path);

	if (!texture->IsReady()) {
		return false;
	}

	textures[name] = texture;

	return true;
}

raylib::Texture2D* TextureLibrary::getTexture(std::string name) {
	return textures[name];
}
