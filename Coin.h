#pragma once

#include "AObject.h"
#include "Player.h"
/*
�A�C�e���ł���u�R�C���v��\����ۃN���X
�A�C�e���̎�����?
*/

class Coin extends Item{
public:
	//�R���X�g���N�^
	//x���W�A�����W�A�t�@�C�����i�摜/�摜�t�@�C����,�I�u�W�F�N�g�̕�,�I�u�W�F�N�g�̍���,�����i�E�����Ȃ�true�j
	Coin(double ax,double ay,char* fname,int size_x,int size_y,bool right);
	//�֐�
	/*
	������player�̃t�B�[���h�ϐ���ύX���āA�A�C�e���̌��ʂ�^����֐�
	*/
	public void Affect(Player player);
	/*
	���̃A�C�e�����ǂ̂悤�Ȏv�l�����邩�i�������Ƃ��j�����肷��
	*/
	public void Think();
	
protected:

	
private:


};