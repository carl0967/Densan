#include "FireBall.h"

//�R���X�g���N�^
FireBall::FireBall(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue){
	super(ax,ay,fname,size_x,size_y,right,damageValue);
	damage = damageValue;
}
//�֐�
FireBall::Think(){
	speed_.x=3;
}

