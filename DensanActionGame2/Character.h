/*
�G�y�ю��@�̒��ۃN���X�B
�V�����G�����ꍇ�͂��̃N���X���p�������N���X�����
*/
#pragma once

#include "DxLib.h"
#include "AObject.h"
#include "Attack.h"
class Field;
class CharacterController;
class Attack;

class Character: public AObject{
public:
	//������x���W,y���W,�ړ����x,�W�����v��,HP,�摜�̃t�@�C����,�����蔻��̔{����X����,Y����,����(�E��true),CharacterController,Attack
	Character(double x,double y,double move_power,double jump_power,int hp ,char* f_name,double size_x,double size_y,bool right,CharacterController* controller,Attack* attack); //�R���X�g���N�^
	virtual ~Character(); //�f�X�g���N�^

	void Jump();   //�W�����v����
	void Walk(bool right); //right=true�@�Ȃ�E�ɁAfalse�Ȃ獶�Ɉړ�����
	void Run(bool right); //Walk��葬���ړ�����


	void NoMove(); //�Ƃ܂�i���E�̈ړ����O�ɂ���j

	void Move();
	void DoAttack(); //�U��������B������
	void Damaged(int damage);  //�_���[�W���󂯂�Ƃ��ɌĂ΂��BHP���O�ɂȂ��alive��false��
	void Think(); //���ɂǂ̂悤�ȍs�������邩�����߂�BCharacterController�ɈϏ��B
	vector<Bullet*> GetBullets(); //�e��Ԃ��֐�

	//�Q�b�^�[
	int hp(){return hp_;} //hp�̃Q�b�^�[
	int maxHp(){return max_hp_;}//maxHp�̃Q�b�^�[
	int GetBulletsSize(){return attack_->GetBulletsSize();} //�����Ă���e�̐���Ԃ�
	double jump_power() {return jump_power_;}

	//�I�[�o�[���C�h
	void Reset();
	virtual void Draw(int offset); //�v���C���[�ŏ���������K�v������̂ŉ��z�֐���

	void set_jump_power(double y);

protected:
	int hp_;  //�̗�
	int max_hp_; //�̗͂̍ő�l
	int status_; //�L�����N�^�[�̏�Ԃ�\��
	double jump_power_;//�W�����v�̃X�s�[�h
	CharacterController *controller_; //�L�����N�^�[�𓮂������߂̃R���g���[��
	Attack* attack_; 


private:


};