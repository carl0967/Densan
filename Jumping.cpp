#include "Jumping.h"

Jumping::Jumping(Character* character,Field* field) :WalkStraight(character,field){
	count=0;
}

void Jumping::Think(){
	//次の移動先のマップ情報を取ってくる

	//もし次が壁なら反転。違うならそのまま歩く
	WalkStraight::Think();

	//5回実行後、ジャンプする
	if(count%5==0&& character_->isAerial()==false){
		WalkStraight::Think();
		character_->Jump();
	}
	count++;
}