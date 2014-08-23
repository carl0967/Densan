/*
敵クラス
*/
#pragma once

#include "Character.h"

class Enemy:public Character{
public:
	//初期のx座標,y座標,移動速度,ジャンプ力,HP,画像のファイル名,当たり判定の倍率のX方向,Y方向（1.0が普通）,向き(右がtrue),CharacterController,Attack
	Enemy(double x,double y,double move_power,double jump_power,int hp ,char* file_name,int size_x,int size_y,CharacterController* controller, Attack* attakck);
};
