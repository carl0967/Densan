/*
Player�p�̃R���g���[��
�L�[�{�[�h���͂ɂ���ē������B
*/
#pragma once

#include "CharacterController.h"

class PlayerController :public CharacterController{
public:
	PlayerController(); //�������͎g��Ȃ�
	PlayerController(Character* character,Field* field); //�R���X�g���N�^
	void Think(); //���ۃN���X��Think�֐����I�[�o�[���C�h

private:
	char key[256];
	void UpdateKey();
};