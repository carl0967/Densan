#pragma once

#include "DxLib.h"

/*
�u�U������v���Ƃ�\�����ۃN���X�̃w�b�_�[�t�@�C��
�S��:����
*/
/*
�X�V:2014/07/21
�X�V���e:���쐬��Ԃ���`��^��������
*/

abstract class Attack{
public:
	//�֐�
	/*
	CreateBullet��bullet�𐶐����Abullets�֒ǉ�
	*/
	void DoAttack(){
		CreateBullet();
	}
	/*
	bullets�ɑ΂��ĕ`��
	*/
	void DrawBullets(){

	}
	/*

	*/
	void MoveBullets(){

	}

	
protected:
	//�t�B�[���h
	ArrayList<Bullet> bullet;
	//�֐�
	abstract CreateBullet();
	
private:
	

};