#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
	// 横幅と高さ
	float width_, height_;

public:
	// コンストラクタ
	Rectangle(float width, float height);

	// 表示
	void Draw() override;

private:
	// サイズ
	float Size() override;
};