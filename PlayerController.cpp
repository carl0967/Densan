#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Character* character) :CharacterController(character){
}
//キー入力によって移動させる
void PlayerController::Think(){
	//キーが押されているなら
	if(GetJoypadInputState( DX_INPUT_KEY_PAD1 )){
		//右が押されているなら右に移動
		if(  CheckHitKey( KEY_INPUT_RIGHT ) == 1 )  character_->Walk(true);
		//左が押されているなら左に移動
		if(CheckHitKey( KEY_INPUT_LEFT ) == 1) character_->Walk(false);
		//Aか上が押されているならジャンプ
		if(( CheckHitKey( KEY_INPUT_A )==1 ||CheckHitKey( KEY_INPUT_UP ) == 1) &&character_->isAerial()==false) character_->Jump();
	}
	//キーが押されていないなら静止
	else character_->NoMove();
}