#pragma once

#include "Bullet.h"
#include <vector>
using namespace std;

class Character;

class Atack
{
public:
	Atack(int damage, int speed, int interval, Character* chara); //�R���X�g���N�^
	void DoAtack(Bullet* bullet); //�e�������
	virtual void DoAtack() = 0;     //�e�𔭎�(���ۃN���X)
	void ThinkBullets(); //�����Ă���S�Ă̒e��Think
	void DrawBullets(int offset);//�e��`��
	~Atack(void);

	//�Q�b�^�[
	vector<Bullet*> bullets(){return bullets_;}
	int GetBulletsSize();
	
protected:
	vector<Bullet*> bullets_;//�e
	Character* chara_; //���̃A�^�b�N�N���X�������Ă���L�����N�^�[
	int damage_;
	int speed_;
	int interval_; //�e�̔��ˊԊu�i�O�̏ꍇ���A�ˏ�ԁj
	int interval_count_;//���ˊԊu�̃J�E���^�[
};

