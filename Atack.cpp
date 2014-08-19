#include "Atack.h"
#include "Character.h"


Atack::Atack(int damage, int speed, int interval, Character* chara)
{
	damage_ = damage;
	speed_ = speed;
	interval_ = interval;
	interval_count_ = interval;
	chara_ = chara;
}

void Atack::DoAtack(Bullet* bullet){
	//発射間隔の判定
	if(interval_count_ >= interval_){
		interval_count_ = 0;
		//bulltsが空なら新しく弾を生成
		if(bullets_.empty()){
			vector<Bullet*>::iterator end = bullets_.end();
			bullets_.insert(end,bullet);
		}
		
		//bulletsの中にaliveがfalseのものを探す
		else{
			int count = -1;
			for(int i=0; i<bullets_.size(); i++){
				if(!bullets_.at(i)->isAlive()){
					count = i;
					break;
				}
			}	
			//全ての弾が生きている(alive_==true)な場合新しく弾を生成
			if(count == -1){
				vector<Bullet*>::iterator end = bullets_.end();
				bullets_.insert(end, bullet);
			}
			//死んでいる弾(alive_==false)がある場合その弾を再利用
			else{
				int dir=0;
				if(chara_->isRight())
					dir = 1;
				else
					dir = -1;
				bullets_.at(count)->Initialize(chara_->GetCenterPosX(),chara_->GetCenterPosY(),dir);
				delete bullet;
			}
		}
	}
}


void Atack::ThinkBullets(){
	for(int i=0; i<bullets_.size(); i++){
		bullets_.at(i)->Think();
		interval_count_++;
		bullets_.at(i)->DieBullet();
	}
}

void Atack::DrawBullets(int offset){
	for(int i=0; i<bullets_.size(); i++){
		bullets_.at(i)->Draw(offset);
	}
}

int Atack::GetBulletsSize(){
	if(bullets_.empty())
		return 0;
	else
		return (int)bullets_.size();
}

Atack::~Atack(void)
{
}
