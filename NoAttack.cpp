#include "NoAttack.h"
#include "EmptyBullet.h"

//コンストラクタ
NoAttack::NoAttack():Attack(){
	
}
//関数
void NoAttack::CreateBullet(){
	Bullet bullet = new EmptyBullet(ax,ay,fname,size_x,size_y,right,damageValue);
	bullets.add(bullet);
}