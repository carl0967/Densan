#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Character* character) :CharacterController(character){
}
//�L�[���͂ɂ���Ĉړ�������
void PlayerController::Think(){
	//�L�[��������Ă���Ȃ�
	if(GetJoypadInputState( DX_INPUT_KEY_PAD1 )){
		//�E��������Ă���Ȃ�E�Ɉړ�
		if(  CheckHitKey( KEY_INPUT_RIGHT ) == 1 )  character_->Walk(true);
		//����������Ă���Ȃ獶�Ɉړ�
		if(CheckHitKey( KEY_INPUT_LEFT ) == 1) character_->Walk(false);
		//A���オ������Ă���Ȃ�W�����v
		if(( CheckHitKey( KEY_INPUT_A )==1 ||CheckHitKey( KEY_INPUT_UP ) == 1) &&character_->isAerial()==false) character_->Jump();
	}
	//�L�[��������Ă��Ȃ��Ȃ�Î~
	else character_->NoMove();
}