/*
�L�����N�^�[���܂������������邾���̃R���g���[��
*/
#pragma once
#include "WalkStraight.h"

class Jumping :public WalkStraight{
public:
	Jumping(); //�������͎g��Ȃ�
	Jumping(Character* character,Field* field); //�R���X�g���N�^
	void Think(); //���ۃN���X��Think�֐����I�[�o�[���C�h
	void Jump();
private:	
	int count;//���s��
};