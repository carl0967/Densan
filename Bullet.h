#pragma once

//#include "DxLib.h"
#include "AObject.h"

/*
�U�����邽�߂́u�e�v��\�����ۃN���X
*/
/*
���ӓ_
�R���X�g���N�^�̈����ɂă_���[�W�ݒ���s���悤�ɂ��Ă��܂�
*/

abstract class Bullet extends AObject{
public:
	//�R���X�g���N�^
	//x���W�A�����W�A�t�@�C�����i�摜/�摜�t�@�C����,�I�u�W�F�N�g�̕�,�I�u�W�F�N�g�̍���,�����i�E�����Ȃ�true�j,�_���[�W��
	Bullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue);
	//�Q�b�^�[
	/*
	�t�B�[���h�ɐݒ肵���_���[�W��Ԃ�
	*/
	int damage(){return damage;}
	//�֐�
	/*
	���̃A�C�e�����ǂ̂悤�ȓ��������邩�����肷��
	��{�I�ɂ͎��g�̃X�s�[�h��ύX����
	�T�u�N���X�ɂĎ������邱��
	*/
	abstract void Think();
	
protected:

	//�t�B�[���h
	/*
	�G�ɂԂ��������ɂǂꂾ���_���[�W��^����̂�
	*/
	int damage;

private:
	
};