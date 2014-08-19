/*
�G�y�ю��@�̒��ۃN���X�B
�V�����G�����ꍇ�͂��̃N���X���p�������N���X�����
*/
#pragma once

#include "DxLib.h"
#include "AObject.h"
#include "Atack.h"
class Field;
class CharacterController;
class Atack;

class Character: public AObject{
public:
	Character(double x,double y,int hp ,char* f_name,int size_x,int size_y,bool right,Atack* atack); //�R���X�g���N�^

	//���ʃN���X�ŋ�����ς������ꍇ�́A�������I�[�o�[���C�h����
	virtual void Jump();   //�W�����v����
	virtual void Walk(bool right); //right=true�@�Ȃ�E�ɁAfalse�Ȃ獶�Ɉړ�����
	virtual void Run(bool right); //Walk��葬���ړ�����

	void NoMove(); //�Ƃ܂�i���E�̈ړ����O�ɂ���j

	void DoAttack(); //�U��������B������
	void Damaged(int damage);  //�_���[�W���󂯂�Ƃ��ɌĂ΂��BHP���O�ɂȂ��alive��false��
	void Think(); //���ɂǂ̂悤�ȍs�������邩�����߂�BCharacterController�ɈϏ��B
	vector<Bullet*> GetBullets(); //�e��Ԃ��֐�

	//�Q�b�^�[
	int hp(){return hp_;} //hp�̃Q�b�^�[
	int maxHp(){return max_hp_;}//maxHp�̃Q�b�^�[
	int GetBulletsSize(){return atack_->GetBulletsSize();} //�����Ă���e�̐���Ԃ�

	//�I�[�o�[���C�h
	void Reset();
	virtual void Draw(int offset); //�v���C���[�ŏ���������K�v������̂ŉ��z�֐���

protected:
	int hp_;  //�̗�
	int max_hp_; //�̗͂̍ő�l
	int status_; //�L�����N�^�[�̏�Ԃ�\��
	CharacterController *controller_; //�L�����N�^�[�𓮂������߂̃R���g���[��
	Atack* atack_;


private:


};