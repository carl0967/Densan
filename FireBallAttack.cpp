#include "EmptyBullet.h"

//コンストラクタ
FireBallAttack::FireBallAttack(){
	
}
//関数
void FireBallAttack::CreateBullet(){
	Bullet bullet = new EmptyBullet(ax,ay,fname,size_x,size_y,right,damageValue);
	bullets.add(bullet);
}