#include "Jumping.h"

Jumping::Jumping(Character* character,Field* field) :WalkStraight(character,field){
}

void Jumping::Think(){
	//���̈ړ���̃}�b�v��������Ă���

	//���������ǂȂ甽�]�B�Ⴄ�Ȃ炻�̂܂ܕ���
	WalkStraight::Think();

	//5����s��W�����v����
	if(count%5==0&& character_->isAerial()==false){
		WalkStraight::Think();
		if(jump%3){
			character_->set_jump_power(14.0);
		}
		else{
			character_->set_jump_power(7.0);
		}
		character_->Jump();
		jump++;
	}
	count++;
}