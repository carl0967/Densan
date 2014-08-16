#include "FireBall.h"

//コンストラクタ
FireBall::FireBall(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue):Bullet(ax,ay,"画像/火炎大砲1(弾右方向).png",size_x,size_y,right,damageValue){
	move_ghandle_=loadg.Load("画像/火炎大砲2(弾右方向).png");
}
//関数
void FireBall::Think(){
	speed_.x=3;
}

