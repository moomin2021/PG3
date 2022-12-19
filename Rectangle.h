#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
	// �����ƍ���
	float width_, height_;

public:
	// �R���X�g���N�^
	Rectangle(float width, float height);

	// �\��
	void Draw() override;

private:
	// �T�C�Y
	float Size() override;
};