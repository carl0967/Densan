#include"Coin.h"
#include "Player.h"

//�R���X�g���N�^
Coin::Coin(double ax,double ay):Item(ax,ay,"�摜/�R�C��1.png", "����/coin_sound.wav",1,1,false){
	move_ghandle_=loadg.Load("�摜/�R�C��2.png");
}
//�֐�
void Coin::Affect(Character* character){
	//�A�C�e����������v���C���[�̃X�R�A�����Z���Ă���
	dynamic_cast<Player*>(character)->AddScore(1);
	//�����o���Ă���(�����t�@�C�����Ȃ��ꍇ�͉����Ȃ�Ȃ�)
	PlaySound();

}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}