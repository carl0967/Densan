#include"Coin.h"

//�R���X�g���N�^
Coin::Coin(double ax,double ay,char* fname,int size_x,int size_y,bool right):Item(ax,ay,"�摜/�R�C��1.png",size_x,size_y,right){
	move_ghandle_=loadg.Load("�摜/�R�C��2.png");
}
//�֐�
void Coin::Affect(Player player){
	player.AddScore(1);
}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}