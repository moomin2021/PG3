#include "Circle.h"
#include <stdio.h>
#include <stdlib.h>

Circle::Circle(float radius) :
#pragma region ‰Šú‰»ƒŠƒXƒg
	radius_(radius)// -> ”¼Œa
#pragma endregion
{
}

float Circle::Size()
{
	// ‰~‚Ì–ÊÏ‚ğ‹‚ß‚é
	return radius_ * radius_ * 3.14f;
}

void Circle::Draw()
{
	printf_s("‰~‚Ì–ÊÏ‚Í%fcm‚Å‚·\n", Size());
}
