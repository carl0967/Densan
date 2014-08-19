#pragma once

#include "Bullet.h"
#include <vector>
using namespace std;

class Character;

class Attack
{
public:
	Attack(int damage, int speed, int interval, Character* chara); //コンストラクタ
	void DoAttack(Bullet* bullet); //弾を一個発射
	virtual void DoAttack() = 0;     //弾を発射(抽象クラス)
	void ThinkBullets(); //生きている全ての弾にThink
	void DrawBullets(int offset);//弾を描画
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
};

