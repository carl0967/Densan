#pragma once

#include "DxLib.h"

/*
�U���ł���u�Ή��e�v��\����ۃN���X
Bullet�̎�����
*/

abstract class FireBall extends Bullet{
public:
	//�R���X�g���N�^
	//x���W�A�����W�A�t�@�C�����i�摜/�摜�t�@�C����,�I�u�W�F�N�g�̕�,�I�u�W�F�N�g�̍���,�����i�E�����Ȃ�true�j,�_���[�W��
	FireBall(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue);
	//�֐�
	/*
	��⍂���ɐݒ肷��
	*/
	abstract void Think();
	
protected:

private:
	
};