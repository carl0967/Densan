/*
���@�N���X
*/

#pragma once

#include "DxLib.h"
#include "Character.h"
#include "NormalAttack.h"


class Player: public Character{
public:
	Player(double x,double y,Field* field);//�R���X�g���N�^
	void addScore(int point); //���_���Z
	void superTime(); //���G���ԊǗ�

	//�Q�b�^�[
	int score() {return score_;}  
	int life(){return life_;}
	bool super(){return super_;}
	int superCount(){return super_count_;}

	//�I�[�o�[���C�h
	void Jump();
	void Damaged(int damage);
	void Reset();
	void Draw(int offset); //���G���Ԓ��̏������������߃I�[�o�[���C�h
private:
	int life_;  //�v���C���[�̎c�@
	int score_; //���_
	bool super_;//�_���[�W��H������ۂ̖��G���Ԕ���p
	int super_count_; //���G���ԃJ�E���g�p
};
