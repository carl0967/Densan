#include "WalkStraight.h"
#include "Character.h"

WalkStraight::WalkStraight(Character* character,Field* field) :CharacterController(character,field){
}

void WalkStraight::Think(){
	character_->Walk(character_->isRight());
}