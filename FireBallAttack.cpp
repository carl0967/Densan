#include "NoAttack.h"
#include "EmptyBullet.h"

//�R���X�g���N�^
FireBallAttack::FireBallAttack(){
	
}
//�֐�
NoAttack::CreateBullet(){
	Bullet bullet = new EmptyBullet(ax,ay,fname,size_x,size_y,right,damageValue);
	bullets.add(bullet);
}