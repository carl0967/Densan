#include "WalkStraight.h"
#include "Character.h"

WalkStraight::WalkStraight(Character* character,Field* field) :CharacterController(character,field){
}

void WalkStraight::Think(){
	//次の移動先のマップ情報を取ってくる
	int next=field_->GetNextMapData(character_->pos(),character_->speed(),character_->isRight());
	//もし次が壁なら反転。違うならそのまま歩く
	if(next==WALL) character_->Walk(!character_->isRight());
	else  character_->Walk(character_->isRight());

}