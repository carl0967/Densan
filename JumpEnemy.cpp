#include "JumpEnemy.h"
#include "Character.h"

JumpEnemy::JumpEnemy(Character* character,Field* field) :CharacterController(character,field){
	count=0;
}

void JumpEnemy::Think(){
	//次の移動先のマップ情報を取ってくる

	//もし次が壁なら反転。違うならそのまま歩く
	if(field_->IsNextMapDataAWall(character_->pos(),character_->speed(),character_->isRight())) character_->Walk(!character_->isRight());
	else  character_->Walk(character_->isRight());

	bool aerial=character_->isAerial();
	if(count%5==0&& character_->isAerial()==false){
		character_->Jump();
	}
	count++;
}