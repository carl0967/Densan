#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Character* character,Field* field) :CharacterController(character,field){
}
//�L�[���͂ɂ���Ĉړ�������
void PlayerController::Think(){
	UpdateKey();
	//�L�[��������Ă���Ȃ�
	if(GetJoypadInputState( DX_INPUT_KEY_PAD1 )){

		//S�L�[��������Ă���Ȃ瑖��
		if(CheckHitKey( KEY_INPUT_S )==1){
			if(  CheckHitKey( KEY_INPUT_RIGHT ) == 1 )  character_->Run(true);
			else if(CheckHitKey( KEY_INPUT_LEFT ) == 1) character_->Run(false);
			else character_->NoMove();

		}
		//�����łȂ��ꍇ�͕���
		else{
			//�E��������Ă���Ȃ�E�Ɉړ�
			if(  CheckHitKey( KEY_INPUT_RIGHT ) == 1 )  character_->Walk(true);
			//����������Ă���Ȃ獶�Ɉړ�
			else if(CheckHitKey( KEY_INPUT_LEFT ) == 1) character_->Walk(false);
			//����ȊO�͐Î~
			else character_->NoMove();
		}


		//A���オ������Ă��āA�W�����v���łȂ��Ȃ�W�����v
		if(( CheckHitKey( KEY_INPUT_A )==1 ||CheckHitKey( KEY_INPUT_UP ) == 1) &&character_->isAerial()==false) character_->Jump();

		//D�������ꂽ�ꍇ�e����
		if(key[KEY_INPUT_D]==1){
			character_->DoAttack();
		}
	}
	//�L�[��������Ă��Ȃ��Ȃ�Î~
	else character_->NoMove();
}

void PlayerController::UpdateKey(){
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll( tmpKey ); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			key[i]++;     // ���Z
		} else {              // ������Ă��Ȃ����
			key[i] = 0;   // 0�ɂ���
		}
	}
}