# ifndef FIELD_H
# define FIELD_H
#pragma once
using namespace std;

class Field
{
//フィールド
private:
	Map map;                    //マップ
	int count;                  //時間計測用
	vector<int> objects;    //全てのオブジェクト管理用
	double gravity;             //重力の値

//メソッド
public:
	Field(void);      //コンストラクタ
	bool MainLoop();  //メインループ

private:
	void Scroll();                  //スクロール処理
	void FallObjects();             //各オブジェクトに対して、空中にいる場合Fallを呼び出す
	void MoveObjects();             //各オブジェクトに対してMoveを呼び出す
	void DrawObjects();             //各オブジェクトに対してDrawを呼び出す
	void ThinkObjects();            //各オブジェクトに対して
	void TouchPlayer2Objects();     //プレイヤー、弾と敵、アイテムとの当たり判定
	void TouchObjects2Wall();       //オブジェクトと壁の当たり判定
	void DeleteObjects();           //生存falgがfalseのオブジェクトを削除
	void CheckOutOfArea();          //画面外にオブジェクトがあれば削除 
	void AddObject(int object_num); //引数のオブジェクトを生成
	
};
#endif
