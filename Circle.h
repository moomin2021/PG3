#pragma once
#include "IShape.h"

class Circle : public IShape {
	// --�����o�ϐ�-- //
private:
	// ���a
	float radius_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	Circle(float radius);

	// �\��
	void Draw() override;

private:
	// �T�C�Y
	float Size() override;
};