#pragma once

#include "DxLib.h"
#include "LoadGraphic.h"


/*
�u���́v�̒��ۃN���X
�G�L�����N�^�[�⎩�@�A�A�C�e���Ȃǂ̋��ʕ������܂Ƃ߂Ă���B
*/


//�Q����������킷�\���́Bx����y�����܂Ƃ߂Ă���B
typedef struct{
	double x;
	double y;
}TwoDimension;

class AObject{
public:
	//�R���X�g���N�^
	//x���W�A�����W�A�t�@�C�����i�摜/�摜�t�@�C����,�I�u�W�F�N�g�̕�,�I�u�W�F�N�g�̍���,�����i�E�����Ȃ�true�j
	AObject(double ax,double ay,char* fname,int size_x,int size_y,bool right);
	void Reset(); //���Z�b�g����
	void Move();                  //���g�̃X�s�[�h���ړ�����
	void Draw(int offset);   //offset���g���Ď��g�̕`��ʒu���Z�o���ĕ`�悷��
	virtual void Think()=0;  //���g�̃X�s�[�h�𑀍삵�čs�������߂�
	void Fall(double gravity);  // �����̏d�͕�������
	void Die(); //�����t���O��false�ɂ���

	void Set_Speed(double speed_x,double speed_y); //�X�s�[�h��ݒ肷��

	void TouchedBlockX(double set_x); //x���Ńu���b�N�ƐڐG�����ꍇ�ɌĂяo��
	void TouchedBlockY(double set_y); //y���Ńu���b�N�ƐڐG�����ꍇ�ɌĂяo��

	//�Q�b�^�[
	TwoDimension pos() {return pos_;}
	TwoDimension speed() {return speed_; }
	TwoDimension size() {return size_;}
	bool isAerial() {return aerial;}
	bool isRight() {return right;}
	bool isAlive() {return alive;}


	//�������B�ݒ肷��ɂ�Field���猻�݂̎��Ԃ�����Ă��Ȃ��ƂȂ�ŁA�R���X�g���N�^�̈�����Field������
	int  made_time() {return made_time_;}

protected:

	int made_time_;   //�������ꂽ���ԁiField����݂��j
	int live_count_;//�������ꂽ����o�߂�������
	int graphic_handle_;  //�ǂ̃������ɉ摜���ǂݍ��܂�Ă��邩��\���n���h��
	int move_ghandle_; //�ړ��A�j���[�V�����p�摜
	TwoDimension pos_; //x,y���W
	TwoDimension first_pos_; //������x,y���W
	TwoDimension speed_; //x,y���̃X�s�[�h
	TwoDimension size_; //�I�u�W�F�N�g�̂������̕��ƁAy�����̍���
	bool alive; //�������Ă����true
	bool right; //������\���B�E�����Ȃ�true�B�������Ȃ�false
	bool first_right;//�����̌���
	bool aerial; //�󒆂ɂ���Ȃ�true�B�n�ʂɐڂ��Ă���Ȃ�false

	static LoadGraphic loadg;  //�摜�̃������Ǘ������邽�߂̃N���X

private:


};