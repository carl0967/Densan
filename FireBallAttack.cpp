#include "EmptyBullet.h"

//�R���X�g���N�^
FireBallAttack::FireBallAttack(){
	
}
//�֐�
void FireBallAttack::CreateBullet(){
	Bullet bullet = new EmptyBullet(ax,ay,fname,size_x,size_y,right,damageValue);
	bullets.add(bullet);
}