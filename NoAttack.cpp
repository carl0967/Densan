#include "NoAttack.h"
#include "EmptyBullet.h"

//�R���X�g���N�^
NoAttack::NoAttack():Attack(){
	
}
//�֐�
void NoAttack::CreateBullet(){
	Bullet bullet = new EmptyBullet(ax,ay,fname,size_x,size_y,right,damageValue);
	bullets.add(bullet);
}