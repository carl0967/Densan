#include "EmptyBullet.h"

//�R���X�g���N�^
EmptyBullet::EmptyBullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue):Bullet(ax,ay,"�摜/��C",size_x,size_y,right,damageValue){
	damage = 0;
	move_ghandle_=loadg.Load("�摜/��C.png");
}
//�֐�
EmptyBullet::Think(){
	Die();
}

