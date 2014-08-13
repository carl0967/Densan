#include"Coin.h"

//コンストラクタ
Coin::Coin(double ax,double ay,char* fname,int size_x,int size_y,bool right){
	super(double ax,double ay,char* fname,int size_x,int size_y,bool right);
}
//関数
Coin::Affect(Player player){
	player.AddScore(1);
}
Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}