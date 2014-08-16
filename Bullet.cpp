#include "Bullet.h"

//コンストラクタ
Bullet::Bullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue):AObject(ax,ay,fname,size_x,size_y,right){
	damage = damageValue;
}
//関数
Bullet::Think();

