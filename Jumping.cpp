#include "Jumping.h"

Jumping::Jumping(Character* character,Field* field) :WalkStraight(character,field){
	count=0;
}

void Jumping::Think(){
	//���̈ړ���̃}�b�v��������Ă���

	//���������ǂȂ甽�]�B�Ⴄ�Ȃ炻�̂܂ܕ���
	WalkStraight::Think();

	//5����s��A�W�����v����
	if(count%5==0&& character_->isAerial()==false){
		WalkStraight::Think();
		character_->Jump();
	}
	count++;
}