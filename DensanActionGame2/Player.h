/*
���@�N���X
*/

#pragma once

#include "DxLib.h"
#include "Character.h"
#include "NormalAttack.h"

//�Q�[�����ǂ̂悤�ȏ�Ԃ���\���񋓌^ ,�����Ȃ�,�Q�[���N���A�[,���̃}�b�v��
enum GAME_STATUS{NOTHING,CLEAR,OVER,NEXT};

class Player: public Character{
public:
	Player(double x,double y,Field* field);//�R���X�g���N�^
	void AddScore(int point); //���_���Z
	void SetGameStatus(GAME_STATUS game_status) {game_status_=game_status;}
	void NextMap();
	void SuperTime(); //���G���ԊǗ�
	void NextMapReset(double x, double y); //���̃}�b�v�ɍs���ۂ̃��Z�b�g����

	//�Q�b�^�[
	int score() {return score_;}  
	int life(){return life_;}
	bool super(){return super_;}
	int superCount(){return super_count_;}
	GAME_STATUS game_status() {return game_status_;}
	bool next_map_flag(){return next_map_flag_;}
	char* next_map(){return next_map_;}
	

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
	GAME_STATUS game_status_;// �Q�[���̃X�e�[�^�X
	int jump_sound_;
	bool next_map_flag_;  //���̃}�b�v�ɍs�����ǂ������f�p
	char* next_map_;      //���ɍs���}�b�v�̃f�[�^�i�[
	int next_map_count_;   //���X�Ƀ}�b�v��i�߂邽�߂̃J�E���^
	string map_name_;//���݂̃X�e�[�W�� (map3 ��@map2 �Ȃǂ�����)

	string IntToString(int number);
};
