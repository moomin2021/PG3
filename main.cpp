#include <stdio.h>
#include <stdlib.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
	// ¶¬
	IShape* shape_[2];
	shape_[0] = new Circle(3.0f);// -> ‰~
	shape_[1] = new Rectangle(10.0f, 5.0f);// -> ‹éŒ`

	// •\Ž¦
	shape_[0]->Draw();
	shape_[1]->Draw();

	return 0;
}