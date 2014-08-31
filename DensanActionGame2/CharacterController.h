/*
Character�̃R���g���[��
�L�����N�^�[���ǂ̂悤�ɓ����̂������߂镔��
Character��Think�֐��̒��ŁA���̃N���X��Think���Ăяo�����

���ۃN���X
*/

#pragma once

#include "DxLib.h"
#include "Field.h"

class Character;

class CharacterController{
public:
	CharacterController(); //�������͎g��Ȃ�
	CharacterController(Character* character,Field* field); //�R���X�g���N�^
	virtual void Think()=0; //�ǂ̂悤�ɓ����������߂�B�������z�֐�
protected:
	Character* character_; //���g��������Ă���L�����N�^�[���Q��
	Field* field_;
};

