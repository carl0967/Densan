#pragma once
#include "aobject.h"

enum Direction{
	RIGHT = 1, LEFT = -1
};

class Bullet :public AObject
{
public:
	Bullet(double x,double y,int damage,int speed, char* fname, int hit_size_x, int hit_size_y,bool right);//�R���X�g���N�^
	virtual void Think() = 0;
	void DieBullet(); //���ꂽ�e�����ł�����
	void Initialize(double x, double y,int direction);//����������(�ďo��������ۂɌĂяo��)
	~Bullet(void);


	//�Q�b�^�[
	int damage(){return damage_;}

protected:
	int damage_;
	int bullet_speed_; //�e�̑��x
	int direction_;   //1�̂Ƃ��E����,-1�̎�������
};

