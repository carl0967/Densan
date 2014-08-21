#include "JumpEnemy.h"
#include "Character.h"

JumpEnemy::JumpEnemy(Character* character,Field* field) :CharacterController(character,field){
	count=0;
}

void JumpEnemy::Think(){
	//���̈ړ���̃}�b�v��������Ă���

	//���������ǂȂ甽�]�B�Ⴄ�Ȃ炻�̂܂ܕ���
	if(field_->IsNextMapDataAWall(character_->pos(),character_->speed(),character_->isRight())) character_->Walk(!character_->isRight());
	else  character_->Walk(character_->isRight());

	bool aerial=character_->isAerial();
	if(count%5==0&& character_->isAerial()==false){
		character_->Jump();
	}
	count++;
}