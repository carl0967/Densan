#include"Coin.h"
#include "Player.h"

//コンストラクタ
Coin::Coin(double ax,double ay):Item(ax,ay,"画像/コイン1.png", "音源/coin_sound.wav",1,1,false){
	move_ghandle_=loadg.Load("画像/コイン2.png");
}
//関数
void Coin::Affect(Character* character){
	//アイテムを取ったプレイヤーのスコアを加算している
	dynamic_cast<Player*>(character)->AddScore(1);
	//音を出している(音源ファイルがない場合は何もならない)
	PlaySound();

}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}