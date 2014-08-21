#include "AttackBullet.h"


AttackBullet::AttackBullet(Character* character,Field* field) :CharacterController(character,field)
{
}


void AttackBullet::Think(){
	character_->DoAttack();
}

AttackBullet::~AttackBullet(void)
{
}
