#include "NormalAttack.h"


NormalAttack::NormalAttack(int damage, int speed, int interval, Character* chara):Attack(damage, speed, interval ,chara)
{
}

void NormalAttack::DoAttack(){
	Attack::DoAttack(new NormalBullet(chara_->GetCenterPosX(), chara_->GetCenterPosY(), damage_, speed_, 1, 1,chara_->isRight()));
}

void NormalAttack::InitializeBullet(int num){
	dynamic_cast<NormalBullet*>(bullets_.at(num))->Initialize(chara_->GetCenterPosX(), chara_->GetCenterPosY(), chara_->isRight());
}

NormalAttack::~NormalAttack(void)
{
}
