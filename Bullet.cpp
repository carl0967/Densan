#include "Bullet.h"

//コンストラクタ
Bullet::Bullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue){
	super(double ax,double ay,char* fname,int size_x,int size_y,bool right);
	damage = damageValue;
}
//関数
Bullet::Think();

