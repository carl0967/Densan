#include "NormalAttack.h"


NormalAttack::NormalAttack(int damage, int speed, int interval, Character* chara):Attack(damage, speed, interval ,chara)
{
}

void NormalAttack::DoAttack(){
	Attack::DoAttack(new NormalBullet(chara_->GetCenterPosX(), chara_->GetCenterPosY(), damage_, speed_, 1, 1,chara_->isRight()));
}

NormalAttack::~NormalAttack(void)
{
}
