#include "Cursor.h"
#include "TextureLibrary.h"

Cursor::Cursor() 
	: RenderEntity() {
	TextureLibrary& t = TextureLibrary::getInstance();
	this->sprite = t.getTexture("cursor");
}

Cursor::~Cursor() {

}

void Cursor::update() {
	sprite->Draw(position, tint);
}