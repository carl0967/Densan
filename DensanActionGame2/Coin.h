#pragma once

#include "AObject.h"
#include "Player.h"
#include "Item.h"
/*
�A�C�e���ł���u�R�C���v��\����ۃN���X
�A�C�e���̎�����
�Ƃ�����X�R�A��������
*/

class Coin: public Item{
public:
	//�R���X�g���N�^
	//x���W�A�����W�A�t�@�C�����i�摜/�摜�t�@�C����,�I�u�W�F�N�g�̕�,�I�u�W�F�N�g�̍���,�����i�E�����Ȃ�true�j
	Coin(double ax,double ay);
	//�֐�
	/*
	������player�̃t�B�[���h�ϐ���ύX���āA�A�C�e���̌��ʂ�^����֐�
	*/
	void Affect(Character* character);
	/*
	���̃A�C�e�����ǂ̂悤�Ȏv�l�����邩�i�������Ƃ��j�����肷��
	*/
	void Think();
	
protected:

	
private:


};