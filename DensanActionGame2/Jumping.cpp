#include "Jumping.h"

Jumping::Jumping(Character* character,Field* field) :WalkStraight(character,field){
	count_=0;
	jump_=0;
}

void Jumping::Think(){
	//���̈ړ���̃}�b�v��������Ă���

	//���������ǂȂ甽�]�B�Ⴄ�Ȃ炻�̂܂ܕ���
	WalkStraight::Think();

	//5����s��W�����v����
	if(count_%5==0&& character_->isAerial()==false){
		WalkStraight::Think();
		if(jump_%3){
			character_->set_jump_power(14.0);
		}
		else{
			character_->set_jump_power(7.0);
		}
		character_->Jump();
		jump_++;
	}
	count_++;
}