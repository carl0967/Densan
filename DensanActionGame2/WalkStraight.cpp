#include "WalkStraight.h"
#include "Character.h"

WalkStraight::WalkStraight(Character* character,Field* field) :CharacterController(character,field){
}

void WalkStraight::Think(){
	
	//���������ǂȂ甽�]�B�Ⴄ�Ȃ炻�̂܂ܕ���
	if(field_->IsNextMapDataAWall(character_->pos(),character_->speed(),character_->isRight())) character_->Walk(!character_->isRight());
	else  character_->Walk(character_->isRight());

}