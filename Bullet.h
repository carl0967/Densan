#pragma once
#include "aobject.h"
#include <math.h>

#define PAI 3.14

class Bullet :public AObject
{
public:
	Bullet(double x,double y,int damage,double move_power, char* fname, double hit_size_x, double hit_size_y);//�R���X�g���N�^
	~Bullet();
	virtual void Think();
	void Move();
	void DieBullet(); //���ꂽ�e�����ł�����
	virtual void Initialize(double x, double y);//����������(�ďo��������ۂɌĂяo��)


	//�Q�b�^�[
	int damage(){return damage_;}

protected:
	int damage_;
	double angle_; //���ˊp�x
};

