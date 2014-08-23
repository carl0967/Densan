#pragma once

#include "Bullet.h"
#include <vector>
using namespace std;

class Character;

class Attack
{
public:
	Attack(int damage, int speed, int interval, Character* chara); //コンストラクタ
	Attack(int damage, int speed, int interval, Character* charam, char* sound_name); //コンストラクタ
	virtual void DoAttack() = 0;
	void DoAttack(Bullet* bullet); //弾を一個発射(発射できない場合はfalseを返す)
	virtual void InitializeBullet(int num) = 0; //引数で指定した弾を初期化
	void ThinkBullets(); //生きている全ての弾にThink
	void MoveBullets();
	void DrawBullets(int offset);//弾を描画
	void ResetBullets();//全ての弾を消す
	void PlaySound(); //発射音を出す
	~Attack(void);

	//ゲッター
	vector<Bullet*> bullets(){return bullets_;}
	int GetBulletsSize();
	
protected:
	vector<Bullet*> bullets_;//弾
	Character* chara_; //このアタッククラスを持っているキャラクター
	int damage_;
	int speed_;
	int interval_; //弾の発射間隔（０の場合超連射状態）
	int interval_count_;//発射間隔のカウンター
	int attack_sound_; //発射音
};

