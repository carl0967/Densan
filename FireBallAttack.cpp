#include "NoAttack.h"
#include "EmptyBullet.h"

//コンストラクタ
FireBallAttack::FireBallAttack(){
	
}
//関数
NoAttack::CreateBullet(){
	Bullet bullet = new EmptyBullet(ax,ay,fname,size_x,size_y,right,damageValue);
	bullets.add(bullet);
}