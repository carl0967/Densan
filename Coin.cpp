#include"Coin.h"

//コンストラクタ
Coin::Coin(double ax,double ay,char* fname,int size_x,int size_y,bool right):Item(ax,ay,"画像/コイン1.png",size_x,size_y,right){
	move_ghandle_=loadg.Load("画像/コイン2.png");
}
//関数
void Coin::Affect(Player player){
	player.AddScore(1);
}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}