#pragma once

class AObject{
public:
	AObject(double x,double y);  
	void Move();                  //自身のスピード分移動する
	void Draw(int offset);   //offsetを使って自身の描画位置を算出して描画する
	virtual void Think()=0;  //自身のスピードを操作して行動を決める
	void TouchedWall();   //壁と当たったときに呼ばれる
	void Fall(double g);  // 引数の重力分落ちる

protected:
	int made_time;   //生成された時間（Fieldからみた）
	static int graphic_handle;  //どのメモリに画像が読み込まれているか
	int x;   //x座標
	int y;  //y座標
	int alive; //生存していればtrue
	int speed_x; //x軸のスピード
	int speed_y; //y軸のスピード
	int width; //オブジェクトの幅 (当たり判定用)
	int height; //オブジェクトの高さ
	bool right; //向きを表す。右向きならtrue。左向きならfalse
	bool aerial; //空中にいるならtrue。地面に接しているならfalse

}