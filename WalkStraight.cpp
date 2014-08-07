#include "WalkStraight.h"
#include "Character.h"

WalkStraight::WalkStraight(Character* character) :CharacterController(character){
}

void WalkStraight::Think(){
	character_->Walk(character_->isRight());
}