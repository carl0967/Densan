#include"Coin.h"
#include "Player.h"

//コンストラクタ
Coin::Coin(double ax,double ay):Item(ax,ay,"Image/coin.png", "Sound/coin_sound.wav",false){
}
//関数
void Coin::Affect(Character* character){
	//アイテムを取ったプレイヤーのスコアを加算している
	dynamic_cast<Player*>(character)->AddScore(1);
	//音を出している(Soundファイルがない場合は何もならない)
	PlaySound();

}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}