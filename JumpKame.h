/*
�G�L�����N�^�[��
�J���N���X
*/
#pragma once
#include "Enemy.h"

class JumpKame:public Enemy{
public:
	JumpKame(double x,double y,Field* field);
	void Jump();//�I�[�o�[���C�h
private:
	int sanpo;//�W�����v������
};
