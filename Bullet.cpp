#include "Bullet.h"

//�R���X�g���N�^
Bullet::Bullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue){
	super(double ax,double ay,char* fname,int size_x,int size_y,bool right);
	damage = damageValue;
}
//�֐�
Bullet::Think();

