/*
���@�N���X
*/

#pragma once

#include "DxLib.h"
#include "Character.h"
#include "NormalAttack.h"

//�Q�[�����ǂ̂悤�ȏ�Ԃ���\���񋓌^ ,�����Ȃ�,�Q�[���N���A�[,���̃}�b�v��
enum GAME_STATUS{NOTHING,CLEAR,NEXT};

class Player: public Character{
public:
	Player(double x,double y,Field* field);//�R���X�g���N�^
	void addScore(int point); //���_���Z
	void ChangeClear() {clear=true;} //clear��true�ɂ���
	void SetGameStatus(GAME_STATUS game_status) {game_status_=game_status;}
	void superTime(); //���G���ԊǗ�

	//�Q�b�^�[
	int score() {return score_;}  
	int life(){return life_;}
	bool super(){return super_;}
	int superCount(){return super_count_;}
	bool IsClear() {return clear;}
	GAME_STATUS game_status() {return game_status_;}
	

	//�I�[�o�[���C�h
	void Jump();
	void Damaged(int damage);
	void Reset();
	void Draw(int offset); //���G���Ԓ��̏������������߃I�[�o�[���C�h
private:
	int life_;  //�v���C���[�̎c�@
	int score_; //���_
	bool super_;//�_���[�W��H������ۂ̖��G���Ԕ���p
	int super_count_; //���G���ԃJ�E���g�p
	bool clear; //�X�e�[�W�N���A�������ǂ����B�����Ȃ�true�B
	GAME_STATUS game_status_;// �Q�[���̃X�e�[�^�X
};
