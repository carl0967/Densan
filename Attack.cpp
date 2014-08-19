#include "Attack.h"
#include "Character.h"


Attack::Attack(int damage, int speed, int interval, Character* chara)
{
	damage_ = damage;
	speed_ = speed;
	interval_ = interval;
	interval_count_ = interval;
	chara_ = chara;
}

void Attack::DoAttack(Bullet* bullet){
	//���ˊԊu�̔���
	if(interval_count_ >= interval_){
		interval_count_ = 0;
		//bullts����Ȃ�V�����e�𐶐�
		if(bullets_.empty()){
			vector<Bullet*>::iterator end = bullets_.end();
			bullets_.insert(end,bullet);
		}
		
		//bullets�̒���alive��false�̂��̂�T��
		else{
			int count = -1;
			for(int i=0; i<bullets_.size(); i++){
				if(!bullets_.at(i)->isAlive()){
					count = i;
					break;
				}
			}	
			//�S�Ă̒e�������Ă���(alive_==true)�ȏꍇ�V�����e�𐶐�
			if(count == -1){
				vector<Bullet*>::iterator end = bullets_.end();
				bullets_.insert(end, bullet);
			}
			//����ł���e(alive_==false)������ꍇ���̒e���ė��p
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


void Attack::ThinkBullets(){
	for(int i=0; i<bullets_.size(); i++){
		bullets_.at(i)->Think();
		interval_count_++;
		bullets_.at(i)->DieBullet();
	}
}

void Attack::DrawBullets(int offset){
	for(int i=0; i<bullets_.size(); i++){
		bullets_.at(i)->Draw(offset);
	}
}

int Attack::GetBulletsSize(){
	if(bullets_.empty())
		return 0;
	else
		return (int)bullets_.size();
}

Attack::~Attack(void)
{
}
