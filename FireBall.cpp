#include "FireBall.h"

//コンストラクタ
FireBall::FireBall(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue){
	super(ax,ay,fname,size_x,size_y,right,damageValue);
	damage = damageValue;
}
//関数
FireBall::Think(){
	speed_.x=3;
}

