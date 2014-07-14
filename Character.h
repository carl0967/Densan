//#ifndef CHARACTER
//#define CHARACTER

#pragma once

#include "DxLib.h"
#include "AObject.h"
//#include "CharacterController.h"
class CharacterController;

class Character: public AObject{
public:
	Character(double x,double y);
	void Jump();
	void Walk(bool right);
	void Run(bool right);

	void DoAttack();
	//�_���[�W���󂯂�Ƃ��ɌĂ΂��BHP���O�ɂȂ��alive��false��
	void Damaged(int damage); 
	void Think();

protected:
	int hp_;  //�̗�
	int status_; //�L�����N�^�[�̏�Ԃ�\��
	CharacterController *controller_;

	//���g�����R���g���[���[�𐶐�����
	//���ʃN���X�ŃI�[�o�[���C�h������
	virtual CharacterController* CreateController(){return NULL;}

private:


};

//#endif