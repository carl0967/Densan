#include "FireBall.h"

//�R���X�g���N�^
FireBall::FireBall(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue):Bullet(ax,ay,"�摜/�Ή���C1(�e�E����).png",size_x,size_y,right,damageValue){
	move_ghandle_=loadg.Load("�摜/�Ή���C2(�e�E����).png");
}
//�֐�
void FireBall::Think(){
	speed_.x=3;
}

