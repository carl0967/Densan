#pragma once

#include "DxLib.h"

/*
���̂ł���u�A�C�e���v��\�����ۃN���X�̃w�b�_�[�t�@�C��
�S��:����
*/
/*
�X�V:2014/07/07
�X�V���e:���쐬��Ԃ���`��^��������
*/

abstract class Item extends AObject{
public:
	//�t�B�[���h

	//�Q�b�^�[
	
	//�֐�
	/*
	������character�̃t�B�[���h�ϐ���ύX���āA�A�C�e���̌��ʂ�^����֐�
	�T�u�N���X�ɂĎ������邱��
	*/
	public abstract void Affect(Character character);
	/*
	�I�[�o�[���C�h�����֐�
	���̃A�C�e�����ǂ̂悤�ȓ��������邩�����肷��
	��{�I�ɂ͎��g�̃X�s�[�h��ύX����
	�T�u�N���X�ɂĎ������邱��
	*/
	public abstract void Think();
	
protected:

	
private:


};