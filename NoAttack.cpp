#include "NoAttack.h"
#include "EmptyBullet.h"

//�R���X�g���N�^
NoAttack::NoAttack(){
	
}
//�֐�
NoAttack::CreateBullet(){
	Bullet bullet = new EmptyBullet(ax,ay,fname,size_x,size_y,right,damageValue);
	bullets.add(bullet);
}