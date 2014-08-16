#include"Coin.h"
#include "Player.h"

//コンストラクタ
Coin::Coin(double ax,double ay):Item(ax,ay,"画像/コイン1.png",32,32,false){
	move_ghandle_=loadg.Load("画像/コイン2.png");
}
//関数
void Coin::Affect(Character* character){
	dynamic_cast<Player*>(character)->addScore(1);

}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}