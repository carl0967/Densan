#include "EmptyBullet.h"

//コンストラクタ
EmptyBullet::EmptyBullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue){
	super(ax,ay,fname,size_x,size_y,right);
	damage = 0;
}
//関数
EmptyBullet::Think(){
	Die();
}

