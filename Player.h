/*
���@�N���X
*/

#pragma once

#include "DxLib.h"
#include "Character.h"


class Player: public Character{
public:
	Player(double x,double y,Field* field);//�R���X�g���N�^
	void addScore(int point); //���_���Z

	//�Q�b�^�[
	int score() {return score_;}  
	int life(){return life_;}

	//�I�[�o�[���C�h
	void Jump();
private:
	int life_;  //�v���C���[�̎c�@
	int score_; //���_
};
