#include "Circle.h"
#include <stdio.h>
#include <stdlib.h>

Circle::Circle(float radius) :
#pragma region ú»Xg
	radius_(radius)// -> ¼a
#pragma endregion
{
}

float Circle::Size()
{
	// ~ÌÊÏðßé
	return radius_ * radius_ * 3.14f;
}

void Circle::Draw()
{
	printf_s("~ÌÊÏÍ%fcmÅ·\n", Size());
}
