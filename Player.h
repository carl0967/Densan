/*
自機クラス
*/

#pragma once

#include "DxLib.h"
#include "Character.h"


class Player: public Character{
public:
	Player(double x,double y,Field* field);//コンストラクタ
	void addScore(int point); //得点加算

	//ゲッター
	int score() {return score_;}  
	int life(){return life_;}

	//オーバーライド
	void Jump();
private:
	int life_;  //プレイヤーの残機
	int score_; //得点
};
