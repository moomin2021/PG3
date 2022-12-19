#include "Rectangle.h"
#include <stdio.h>
#include <stdlib.h>

Rectangle::Rectangle(float width, float height) :
#pragma region 初期化リスト
	width_(width),
	height_(height)
#pragma endregion
{
}

void Rectangle::Draw()
{
	printf_s("四角形の面積%fcmです\n", Size());
}

float Rectangle::Size()
{
	// 面積を計算
	return width_ * height_;
}
