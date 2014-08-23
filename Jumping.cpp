#include "Jumping.h"

Jumping::Jumping(Character* character,Field* field) :WalkStraight(character,field){
}

void Jumping::Think(){
	//次の移動先のマップ情報を取ってくる

	//もし次が壁なら反転。違うならそのまま歩く
	WalkStraight::Think();

	//5回実行後ジャンプする
	if(count%5==0&& character_->isAerial()==false){
		WalkStraight::Think();
		if(jump%3){
			character_->set_jump_power(14.0);
		}
		else{
			character_->set_jump_power(7.0);
		}
		character_->Jump();
		jump++;
	}
	count++;
}