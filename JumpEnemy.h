/*
�L�����N�^�[���܂������������邾���̃R���g���[��
*/
#pragma once

#include "CharacterController.h"

class JumpEnemy :public CharacterController{
public:
	JumpEnemy(); //�������͎g��Ȃ�
	JumpEnemy(Character* character,Field* field); //�R���X�g���N�^
	void Think(); //���ۃN���X��Think�֐����I�[�o�[���C�h
	void Jump();
private:	
	int count;//���s��
	//bool EnemySightIn();//���E���Ƀv���C���[�����邩
};