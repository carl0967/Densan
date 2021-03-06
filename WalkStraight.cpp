#include "WalkStraight.h"
#include "Character.h"

WalkStraight::WalkStraight(Character* character,Field* field) :CharacterController(character,field){
}

void WalkStraight::Think(){
	
	//もし次が壁なら反転。違うならそのまま歩く
	if(field_->IsNextMapDataAWall(character_->pos(),character_->speed(),character_->isRight())) character_->Walk(!character_->isRight());
	else  character_->Walk(character_->isRight());

}