#include"Coin.h"
#include "Player.h"

//�R���X�g���N�^
Coin::Coin(double ax,double ay):Item(ax,ay,"�摜/�R�C��1.png",32,32,false){
	move_ghandle_=loadg.Load("�摜/�R�C��2.png");
}
//�֐�
void Coin::Affect(Character* character){
	dynamic_cast<Player*>(character)->addScore(1);

}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}