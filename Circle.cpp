#include "Circle.h"
#include <stdio.h>
#include <stdlib.h>

Circle::Circle(float radius) :
#pragma region ���������X�g
	radius_(radius)// -> ���a
#pragma endregion
{
}

float Circle::Size()
{
	// �~�̖ʐς����߂�
	return radius_ * radius_ * 3.14f;
}

void Circle::Draw()
{
	printf_s("�~�̖ʐς�%fcm�ł�\n", Size());
}
