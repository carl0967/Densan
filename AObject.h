#pragma once

#include "DxLib.h"
#include "Field.h"


/*
�u���́v�̒��ۃN���X
*/
/*
�ύX��������
���W��X�s�[�h,�T�C�Y��x,y���\���̂ł܂Ƃ߂�
*/

//�Q����������킷�\���́Bx����y�����܂Ƃ߂Ă���B
typedef struct{
	double x;
	double y;
}TwoDimension;

class AObject{
public:
	AObject(double ax,double ay,Field field);
	void Move();                  //���g�̃X�s�[�h���ړ�����
	void Draw(int offset);   //offset���g���Ď��g�̕`��ʒu���Z�o���ĕ`�悷��
	void Think();  //���g�̃X�s�[�h�𑀍삵�čs�������߂�
	void TouchedWall(double wall_x);   //�ǂƓ��������Ƃ��ɌĂ΂��
	void TouchedFloor(double floor_y);  //���Ɠ��������Ƃ��ɌĂ΂��
	void Fall(double gravity);  // �����̏d�͕�������
	void Die(); //�����t���O��false�ɂ���

	//�Q�b�^�[
	TwoDimension GetPos() {return pos;}
	TwoDimension GetSpeed() {return speed; }
	bool isAerial() {return aerial;}
	bool isRight() {return right;}
	bool isAlive() {return alive;}

	//�������B�ݒ肷��ɂ�Field���猻�݂̎��Ԃ�����Ă��Ȃ��ƂȂ�ŁA�R���X�g���N�^�̈�����Field������
	int  get_made_time() {return made_time;}

protected:

	int made_time;   //�������ꂽ���ԁiField����݂��j
	static int graphic_handle;  //�ǂ̃������ɉ摜���ǂݍ��܂�Ă��邩
	TwoDimension pos; //x,y���W
	TwoDimension speed; //x,y���̃X�s�[�h
	TwoDimension size; //�I�u�W�F�N�g�̂������̕��ƁAy�����̍���
	bool alive; //�������Ă����true
	bool right; //������\���B�E�����Ȃ�true�B�������Ȃ�false
	bool aerial; //�󒆂ɂ���Ȃ�true�B�n�ʂɐڂ��Ă���Ȃ�false
	char* file_name; //�摜�t�@�C����

	 //�t�@�C�����A�T�C�Y�Aright�����������郁�\�b�h�B
	//���ʃN���X�ł͂�����I�[�o�[���C�h����΂������Ǝv���쐬���Ă݂��B
	//�R���X�g���N�^�ŌĂ΂��
	void init(); 


};