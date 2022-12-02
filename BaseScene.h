#pragma once
#include "Cell.h"

class BaseScene {
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual void Initialize(CELL * cell) = 0;
	virtual void Update() = 0;
};