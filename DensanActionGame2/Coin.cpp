#include"Coin.h"
#include "Player.h"

//�R���X�g���N�^
Coin::Coin(double ax,double ay):Item(ax,ay,"Image/coin.png", "Sound/coin_sound.wav",false){
}
//�֐�
void Coin::Affect(Character* character){
	//�A�C�e����������v���C���[�̃X�R�A�����Z���Ă���
	dynamic_cast<Player*>(character)->AddScore(1);
	//�����o���Ă���(Sound�t�@�C�����Ȃ��ꍇ�͉����Ȃ�Ȃ�)
	PlaySound();

}
void Coin::Think(){
	speed_.x = 0;
	speed_.y = 0;
}