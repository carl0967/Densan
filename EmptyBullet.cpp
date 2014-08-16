#include "EmptyBullet.h"

//コンストラクタ
EmptyBullet::EmptyBullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue):Bullet(ax,ay,"画像/空砲",size_x,size_y,right,damageValue){
	damage = 0;
	move_ghandle_=loadg.Load("画像/空砲.png");
}
//関数
EmptyBullet::Think(){
	Die();
}

