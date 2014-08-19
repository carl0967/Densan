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
	//”­ËŠÔŠu‚Ì”»’è
	if(interval_count_ >= interval_){
		interval_count_ = 0;
		//bullts‚ª‹ó‚È‚çV‚µ‚­’e‚ğ¶¬
		if(bullets_.empty()){
			vector<Bullet*>::iterator end = bullets_.end();
			bullets_.insert(end,bullet);
		}
		
		//bullets‚Ì’†‚Éalive‚ªfalse‚Ì‚à‚Ì‚ğ’T‚·
		else{
			int count = -1;
			for(int i=0; i<bullets_.size(); i++){
				if(!bullets_.at(i)->isAlive()){
					count = i;
					break;
				}
			}	
			//‘S‚Ä‚Ì’e‚ª¶‚«‚Ä‚¢‚é(alive_==true)‚Èê‡V‚µ‚­’e‚ğ¶¬
			if(count == -1){
				vector<Bullet*>::iterator end = bullets_.end();
				bullets_.insert(end, bullet);
			}
			//€‚ñ‚Å‚¢‚é’e(alive_==false)‚ª‚ ‚éê‡‚»‚Ì’e‚ğÄ—˜—p
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
