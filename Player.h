/*
���@�N���X
*/

#pragma once

#include "DxLib.h"
#include "Character.h"


class Player: public Character{
public:
	Player(double x,double y);//�R���X�g���N�^
	void addScore(int point); //���_���Z

	//�Q�b�^�[
	int score() {return score_;}  
	int life(){return life_;}
protected:
	void init(); //�I�[�o�[���C�h���������������B�摜�̐ݒ�Ȃ�
private:
	int life_;  //�v���C���[�̎c�@
	int score_; //���_

};
