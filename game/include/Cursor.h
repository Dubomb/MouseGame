#pragma once

#include <raylib.h>
#include <raylib-cpp.hpp>

#include "RenderEntity.h"

class Cursor : public RenderEntity {
public:
	Cursor();
	~Cursor();

	void update() override;
};