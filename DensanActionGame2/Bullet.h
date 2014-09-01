#pragma once
#include "aobject.h"
#include <math.h>

#define PAI 3.14

class Bullet :public AObject
{
public:
	//������x���W,y���W,�ړ����x,�摜��,�����蔻��̔{��
	Bullet(double x,double y,int damage,double move_power, char* fname);//�R���X�g���N�^
	~Bullet();//�f�X�g���N�^
	virtual void Think();
	void Move();
	void DieBullet(); //���ꂽ�e�����ł�����
	virtual void Initialize(double x, double y);//����������(�ďo��������ۂɌĂяo��)

	int damage(){return damage_;}


protected:
	double angle_; //���ˊp�x
	int damage_; //�e�̃_���[�W
};

