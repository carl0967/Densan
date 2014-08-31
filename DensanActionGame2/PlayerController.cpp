#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Character* character,Field* field) :CharacterController(character,field){
}
//キー入力によって移動させる
void PlayerController::Think(){
	UpdateKey();
	//キーが押されているなら
	if(GetJoypadInputState( DX_INPUT_KEY_PAD1 )){

		//Sキーが押されているなら走る
		if(CheckHitKey( KEY_INPUT_S )==1){
			if(  CheckHitKey( KEY_INPUT_RIGHT ) == 1 )  character_->Run(true);
			else if(CheckHitKey( KEY_INPUT_LEFT ) == 1) character_->Run(false);
			else character_->NoMove();

		}
		//そうでない場合は歩く
		else{
			//右が押されているなら右に移動
			if(  CheckHitKey( KEY_INPUT_RIGHT ) == 1 )  character_->Walk(true);
			//左が押されているなら左に移動
			else if(CheckHitKey( KEY_INPUT_LEFT ) == 1) character_->Walk(false);
			//それ以外は静止
			else character_->NoMove();
		}


		//Aか上が押されていて、ジャンプ中でないならジャンプ
		if(( CheckHitKey( KEY_INPUT_A )==1 ||CheckHitKey( KEY_INPUT_UP ) == 1) &&character_->isAerial()==false) character_->Jump();

		//Dが押された場合弾発射
		if(key[KEY_INPUT_D]==1){
			character_->DoAttack();
		}
	}
	//キーが押されていないなら静止
	else character_->NoMove();
}

void PlayerController::UpdateKey(){
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll( tmpKey ); // 全てのキーの入力状態を得る
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i番のキーコードに対応するキーが押されていたら
			key[i]++;     // 加算
		} else {              // 押されていなければ
			key[i] = 0;   // 0にする
		}
	}
}