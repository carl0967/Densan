#pragma once

#include "DxLib.h"

/*
���̂ł���u�e�v��\�����ۃN���X�̃w�b�_�[�t�@�C��
�S��:����
*/
/*
�X�V:2014/07/21
�X�V���e:���쐬��Ԃ���`��^��������
*/

abstract class Bullet extends AObject{
public:
	//�Q�b�^�[
	/*

	*/
	int damage(){
		return damage;
	}
	//�֐�
	/*
	�I�[�o�[���C�h�����֐�
	���̃A�C�e�����ǂ̂悤�ȓ��������邩�����肷��
	��{�I�ɂ͎��g�̃X�s�[�h��ύX����
	�T�u�N���X�ɂĎ������邱��
	*/
	public abstract void Think();
	
protected:

	
private:
	//�t�B�[���h
	/*
	�G�ɂԂ��������ɂǂꂾ���_���[�W��^����̂�
	*/
	int damage;

};