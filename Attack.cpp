#include "Attack.h"


//コンストラクタ
Attack::Attack(){
	
}
//関数
Attack::DoAttack(){
	CreateBullet();
	DrawBullets();
	MoveBullets();
}
Attack::DrawBullets(int offset){
	for(Bullet allBullets : bullets){
		allBullets.Draw(offset);
	}
}
Attack::MoveBullets(){
	for(Bullet allBullets : bullets){
		allBullets.Move();
	}
}
Attack::CreateBullet();