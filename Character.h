#pragma once

#include "DxLib.h"
#include "AObject.h"

class Character: public AObject{
public:
	Character(double x,double y);
	void Jump();
	void Walk(bool right);
	void Run(bool right);

	void DoAttack();
	//�_���[�W���󂯂�Ƃ��ɌĂ΂��BHP���O�ɂȂ��alive��false��
	void Damaged(int damage); 
	virtual void Think()=0;

protected:
	int hp_;  //�̗�
	int status_; //�L�����N�^�[�̏�Ԃ�\��

private:



};