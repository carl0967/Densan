#pragma once

//#include "DxLib.h"
#include "AObject.h"
#include "Character.h"

/*
���̂ł���u�A�C�e���v��\�����ۃN���X
*/

class Item :public  AObject{
public:
	//�R���X�g���N�^
	//x���W�A�����W�A�t�@�C�����i�摜/�摜�t�@�C����,�I�u�W�F�N�g�̕�,�I�u�W�F�N�g�̍���,�����i�E�����Ȃ�true�j
	Item(double ax,double ay,char* fname,int size_x,int size_y,bool right);
	//x���W�A�����W�A�t�@�C�����i�摜/�摜�t�@�C����,�I�u�W�F�N�g�̕�,�I�u�W�F�N�g�̍���,�����i�E�����Ȃ�true,�����t�@�C���̃p�X
	Item(double ax,double ay,char* fname, char* sound_name,int size_x,int size_y,bool right);

	//�֐�
	/*
	������character�̃t�B�[���h�ϐ���ύX���āA�A�C�e���̌��ʂ�^����֐�
	�T�u�N���X�ɂĎ������邱��
	*/
	virtual void Affect(Character* character) = 0;
	//�����o���֐�
	void PlaySound();
	/*
	�I�[�o�[���C�h�����֐�
	���̃A�C�e�����ǂ̂悤�ȓ��������邩�����肷��
	��{�I�ɂ͎��g�̃X�s�[�h��ύX����
	�T�u�N���X�ɂĎ������邱��
	*/
	 //void Think();
protected:
	int item_sound_;
	
private:


};