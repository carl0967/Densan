#pragma once

#include "DxLib.h"
#include "LoadGraphic.h"


/*
「物体」の抽象クラス
敵キャラクターや自機、アイテムなどの共通部分をまとめている。
*/

//プレイヤーか敵かアイテムかを判断するよう
enum ObjectType{O_PLAYER,O_ENEMY,O_ITEM};

//２次元をあらわす構造体。x軸とy軸をまとめている。
typedef struct{
	double x;
	double y;
}TwoDimension;

class AObject{
public:
	//コンストラクタ
	//x座標、ｙ座標、ファイル名（画像/画像ファイル名,オブジェクトの当たり幅,オブジェクトの高さ,向き（右向きならtrue）
	AObject(double ax,double ay,char* fname,int hit_size_x,int hit_size_y,bool right);
	virtual ~AObject();
	virtual void Reset(); //リセット処理
	void Move();                  //自身のスピード分移動する
	virtual void Draw(int offset);   //offsetを使って自身の描画位置を算出して描画する
	virtual void Think()=0;  //自身のスピードを操作して行動を決める
	void Fall(double gravity);  // 引数の重力分落ちる
	void Die(); //生存フラグをfalseにする
	void Revival() {alive=true;} //生存フラグをtrueにする

	void Set_Speed(double speed_x,double speed_y); //スピードを設定する

	void TouchedBlockX(double set_x); //x軸でブロックと接触した場合に呼び出す
	void TouchedBlockY(double set_y); //y軸でブロックと接触した場合に呼び出す

	void GetObjectSize();//オブジェクトのサイズを画像から読み取る

	double GetCenterPosX(); //オブジェクトの中心座標を返す
	double GetCenterPosY(); //オブジェクトの中心座標を返す

	//ゲッター
	TwoDimension pos() {return pos_;}
	TwoDimension speed() {return speed_; }
	TwoDimension size() {return size_;}
	TwoDimension hit_size() {return hit_size_;}
	bool isAerial() {return aerial;}
	bool isRight() {return right;}
	bool isAlive() {return alive;}
	int object_type(){return object_type_;}

protected:
	int live_count_;//生成されたから経過した時間
	int graphic_handle_;  //どのメモリに画像が読み込まれているかを表すハンドル
	int move_ghandle_; //移動アニメーション用画像
	TwoDimension pos_; //x,y座標
	TwoDimension first_pos_; //初期のx,y座標
	TwoDimension speed_; //x,y軸のスピード
	TwoDimension size_; //オブジェクトのｘ方向の幅と、y方向の高さ
	TwoDimension hit_size_;//当たり判定の倍率サイズ
	bool alive; //生存していればtrue
	bool right; //向きを表す。右向きならtrue。左向きならfalse
	bool first_right;//初期の向き
	bool aerial; //空中にいるならtrue。地面に接しているならfalse
	int object_type_;//どのオブジェクトか判断用

	static LoadGraphic loadg;  //画像のメモリ管理をするためのクラス

private:


};