# ifndef FIELD_H
# define FIELD_H
#pragma once
#include "Map.h"
#include"AObject.h"
#include "Character.h"
#include <math.h>
#include <vector>
using namespace std;

class Field
{
//フィールド
private:
	Map map_;                    //マップ
	int count_;                  //時間計測用
	vector<AObject*> objects_;    //全てのオブジェクト管理用
	vector<Character*> charas_;
	double gravity_;             //重力の値
	int offset;                  //オフセット
	
//メソッド
public:
	Field(Map map);   //コンストラクタ
	bool MainLoop();  //メインループ
	

private:
	void Scroll();                       //スクロール処理
	void FallObjects();                  //各オブジェクトに対して、空中にいる場合Fallを呼び出す
	void MoveObjects();                  //各オブジェクトに対してMoveを呼び出す
	void DrawObjects();                  //各オブジェクトに対してDrawを呼び出す
	void ThinkObjects();                 //各オブジェクトに対して
	void TouchPlayer2Objects();          //プレイヤー、弾と敵、アイテムとの当たり判定
	void TouchObjects2Wall();            //オブジェクトと壁の当たり判定
	void DeleteObjects();                //生存falgがfalseのオブジェクトを削除
	void CheckOutOfArea();               //画面外にオブジェクトがあれば削除 
	void AddObject(AObject *object_num); //引数のオブジェクトを生成
	int count(){return count_;}          //countのゲッター
	void CalcOffset();                   //offsetを計算
	int PixelToTiles(double pixels);     //ピクセル単位をタイル単位に変換
	int TilesToPixels(int tiles);        //タイル単位をピクセル単位に変換
	bool JudgeCircle(int x1, int y1, int r1, int x2, int y2, int r2) //円同士のの当たり判定
	
};
#endif
