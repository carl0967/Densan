#include "Attack.h"


//�R���X�g���N�^
Attack::Attack(){
	
}
//�֐�
Attack::DoAttack(){
	CreateBullet();
	DrawBullets();
	MoveBullets();
}
void Attack::DrawBullets(int offset){
	for(Bullet allBullets : bullets){
		allBullets.Draw(offset);
	}
}
void Attack::MoveBullets(){
	for(Bullet allBullets : bullets){
		allBullets.Move();
	}
}
void Attack::CreateBullet();