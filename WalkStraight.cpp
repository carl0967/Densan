#include "WalkStraight.h"
#include "Character.h"

WalkStraight::WalkStraight(Character* character,Field* field) :CharacterController(character,field){
}

void WalkStraight::Think(){
	//���̈ړ���̃}�b�v��������Ă���
	int next=field_->GetNextMapData(character_->pos(),character_->speed(),character_->isRight());
	//���������ǂȂ甽�]�B�Ⴄ�Ȃ炻�̂܂ܕ���
	if(next==WALL) character_->Walk(!character_->isRight());
	else  character_->Walk(character_->isRight());

}