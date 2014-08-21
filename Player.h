/*
自機クラス
*/

#pragma once

#include "DxLib.h"
#include "Character.h"
#include "NormalAttack.h"

//ゲームがどのような状態かを表す列挙型 ,何もなし,ゲームクリアー,次のマップへ
enum GAME_STATUS{NOTHING,CLEAR,NEXT};

class Player: public Character{
public:
	Player(double x,double y,Field* field);//コンストラクタ
	void addScore(int point); //得点加算
	void ChangeClear() {clear=true;} //clearをtrueにする
	void SetGameStatus(GAME_STATUS game_status) {game_status_=game_status;}
	void superTime(); //無敵時間管理

	//ゲッター
	int score() {return score_;}  
	int life(){return life_;}
	bool super(){return super_;}
	int superCount(){return super_count_;}
	bool IsClear() {return clear;}
	GAME_STATUS game_status() {return game_status_;}
	

	//オーバーライド
	void Jump();
	void Damaged(int damage);
	void Reset();
	void Draw(int offset); //無敵時間中の処理を書くためオーバーライド
private:
	int life_;  //プレイヤーの残機
	int score_; //得点
	bool super_;//ダメージを食らった際の無敵時間判定用
	int super_count_; //無敵時間カウント用
	bool clear; //ステージクリアしたかどうか。したならtrue。
	GAME_STATUS game_status_;// ゲームのステータス
};
