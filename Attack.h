#pragma once

#include "AObject.h"
#include "Bullet.h"

/*
�u�U������v���Ƃ�\�����ۃN���X
*/

/*
�X�V�ɂ����钍�ӓ_
DrawBullets�Ɉ�����ǉ�
offset����������悤�ɂ���
*/

abstract class Attack{
public:
	//�R���X�g���N�^
	Attack();
	//�֐�
	/*
	CreateBullet��bullet�𐶐����Abullets�֒ǉ�
	DrawBullets�Œe��`��
	MoveBullets�œ�����
	*/
	void DoAttack();
	/*
	bullets�ɑ΂��ĕ`��
	*/
	void DrawBullets(int offset);
	/*
	bullets�𓮂���
	*/
	void MoveBullets();

	
protected:
	//�t�B�[���h
	//���������e�̕ۊǏꏊ
	ArrayList<Bullet> bullets;
	//�֐�
	//�e�𐶐�����
	abstract CreateBullet();
	
private:
	

};