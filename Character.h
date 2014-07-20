//#ifndef CHARACTER
//#define CHARACTER

#pragma once

#include "DxLib.h"
#include "AObject.h"
//#include "CharacterController.h"
class CharacterController;

class Character: public AObject{
public:
	Character(double x,double y); //�R���X�g���N�^
	void Jump();   //�W�����v����
	void Walk(bool right); //right=true�@�Ȃ�E�ɁAfalse�Ȃ獶�Ɉړ�����
	void Run(bool right); //�BWalk��葬���ړ�����

	//void Set_Speed(double speed_x,double speed_y); //speed�̃Z�b�^�[
	void NoMove(); //�Ƃ܂�
	void DoAttack(); //�U��������B������
	void Damaged(int damage);  //�_���[�W���󂯂�Ƃ��ɌĂ΂��BHP���O�ɂȂ��alive��false��
	void Think(); //���ɂǂ̂悤�ȍs�������邩�����߂�BCharacterController�ɈϏ��B

protected:
	int hp_;  //�̗�
	int status_; //�L�����N�^�[�̏�Ԃ�\��
	CharacterController *controller_;


private:


};

//#endif