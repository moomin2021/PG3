#include "Rectangle.h"
#include <stdio.h>
#include <stdlib.h>

Rectangle::Rectangle(float width, float height) :
#pragma region ���������X�g
	width_(width),
	height_(height)
#pragma endregion
{
}

void Rectangle::Draw()
{
	printf_s("�l�p�`�̖ʐ�%fcm�ł�\n", Size());
}

float Rectangle::Size()
{
	// �ʐς��v�Z
	return width_ * height_;
}
