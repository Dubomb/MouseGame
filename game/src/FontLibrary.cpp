#include "FontLibrary.h"

FontLibrary::FontLibrary() {

}

FontLibrary::~FontLibrary() {
	for (const auto& pair : fonts) {
		delete pair.second;
	}
}

FontLibrary& FontLibrary::getInstance() {
	static FontLibrary instance;
	return instance;
}

bool FontLibrary::loadFont(std::string path, std::string name) {
	raylib::Font* font = new raylib::Font(path);

	if (!font->IsReady()) {
		return false;
	}

	fonts[name] = font;

	return true;
}

raylib::Font* FontLibrary::getFont(std::string name) {
	return fonts[name];
}
