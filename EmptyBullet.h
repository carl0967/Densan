#pragma once

#include "DxLib.h"

/*
�U���Ɏg�p����u�e���Ȃ��v���Ƃ�\����ۃN���X
Bullet�̎�����
*/

abstract class EmptyBullet extends Bullet{
public:
	//�R���X�g���N�^
	EmptyBullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue);
	//�֐�
	/*
	�������Ȃ��ŏ��ł�����
	*/
	void Think();
	
protected:

	//�t�B�[���h
	
private:
	
};