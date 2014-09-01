/*
自機クラス
*/

#pragma once

#include "DxLib.h"
#include "Character.h"
#include "NormalAttack.h"

//ゲームがどのような状態かを表す列挙型 ,何もなし,ゲームクリアー,次のマップへ
enum GAME_STATUS{NOTHING,CLEAR,OVER,NEXT};

class Player: public Character{
public:
	Player(double x,double y,Field* field);//コンストラクタ
	void AddScore(int point); //得点加算
	void SetGameStatus(GAME_STATUS game_status) {game_status_=game_status;}
	void NextMap();
	void SuperTime(); //無敵時間管理
	void NextMapReset(double x, double y); //次のマップに行く際のリセット処理

	//ゲッター
	int score() {return score_;}  
	int life(){return life_;}
	bool super(){return super_;}
	int superCount(){return super_count_;}
	GAME_STATUS game_status() {return game_status_;}
	bool next_map_flag(){return next_map_flag_;}
	char* next_map(){return next_map_;}
	

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
	GAME_STATUS game_status_;// ゲームのステータス
	int jump_sound_;
	bool next_map_flag_;  //次のマップに行くかどうか判断用
	char* next_map_;      //次に行くマップのデータ格納
	int next_map_count_;   //次々にマップを進めるためのカウンタ
	string map_name_;//現在のステージ名 (map3 や　map2 などが入る)

	string IntToString(int number);
};
