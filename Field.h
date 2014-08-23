
#pragma once
#include "Map.h"
#include"AObject.h"
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include "ObjectManager.h"
#include <math.h>
#include <vector>
#include<typeinfo>

using namespace std;

class Field
{
//フィールド
private:
	Map* map_;                    //マップ
	ObjectManager* obj_manager_; 
	int count_;                  //時間計測用
	vector<AObject*> objects_;   //全てのオブジェクト管理用
	Player* player_;              //プレイヤー管理用
	double gravity_;             //重力の値
	int offset_;                 //オフセット

	bool menu_flag;              //メニュー画面に戻るかどうか判定用
	int wait_count_;

	int end_graphic_handle;      //ゲームオーバー画像
	int clear_graphic_handle;    //ゲームクリア画像

	int BGM;                     //BGM用
	
public:
	Field(); //仮コンストラクタ
	Field(Map* map);   //コンストラクタ
	int MainLoop();  //メインループ	
	bool IsNextMapDataAWall(TwoDimension chara_pos, TwoDimension chara_speed, bool right);
	TwoDimension GetPlayerPos();//プレイヤーの座標を返す関数
	int count(){return count_;}          //countのゲッター
	Player* player(){return player_;} //プレイヤーを返す
	~Field(); //デストラクタ

private:
	void Initialize();                   //初期化処理
	void Scroll();                       //スクロール処理
	void FallObjects();                  //各オブジェクトに対して、空中にいる場合Fallを呼び出す
	void MoveObjects();                  //各オブジェクトに対してMoveを呼び出す
	void DrawObjects();                  //各オブジェクトに対してDrawを呼び出す
	void ThinkObjects();                 //各オブジェクトに対して
	void TouchPlayerToObjects();          //プレイヤー、弾と敵、アイテムとの当たり判定
	void TouchObjectsToWall();            //オブジェクトと壁の当たり判定
	void BulletTouchWall();                //壁と弾の当たり判定
	void Reset();                        //プレイヤー死亡時のリセット関数
	//void DeleteObjects();                //生存falgがfalseのオブジェクトを削除
	void GameOver();                     //ゲームオーバー処理
	void GameClear();                    //ゲームクリア処理                      
	void CheckOutOfArea();               //画面外の敵を殺す
	void DownObjectsDie();               //画面下のオブジェクトを殺す
	void AddObject(AObject *object_num, bool isBegin); //引数のオブジェクトを生成
	int PixelToTiles(double pixels);     //ピクセル単位をタイル単位に変換
	int TilesToPixels(int tiles);        //タイル単位をピクセル単位に変換
	bool JudgeCircle(int x1, int y1, int r1, int x2, int y2, int r2); //円同士のの当たり判定
	bool JudgeHitCharacters(AObject* p, AObject* e); //キャラクター同士の当たり判定
	void FindObject(int from_y,int to_y,int from_x, int to_x);   //描画エリアに入ったenemyの生存フラグをtrueにする

};

