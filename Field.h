
# ifndef FIELD_H
# define FIELD_H
#pragma once
#include "Map.h"
#include"AObject.h"
#include "Character.h"
#include "Player.h"
#include <math.h>
#include <vector>
using namespace std;

class Field
{
//�t�B�[���h
private:
	Map* map_;                    //�}�b�v
	int count_;                  //���Ԍv���p
	vector<AObject*> objects_;   //�S�ẴI�u�W�F�N�g�Ǘ��p
	vector<Character*> charas_;  
	double gravity_;             //�d�͂̒l
	int offset_;                  //�I�t�Z�b�g
	

public:
	Field(); //���R���X�g���N�^
	Field(Map* map);   //�R���X�g���N�^
	bool MainLoop();  //���C�����[�v
	

private:
	void Scroll();                       //�X�N���[������
	void FallObjects();                  //�e�I�u�W�F�N�g�ɑ΂��āA�󒆂ɂ���ꍇFall���Ăяo��
	void MoveObjects();                  //�e�I�u�W�F�N�g�ɑ΂���Move���Ăяo��
	void DrawObjects();                  //�e�I�u�W�F�N�g�ɑ΂���Draw���Ăяo��
	void ThinkObjects();                 //�e�I�u�W�F�N�g�ɑ΂���
	void TouchPlayer2Objects();          //�v���C���[�A�e�ƓG�A�A�C�e���Ƃ̓����蔻��
	void TouchObjects2Wall();            //�I�u�W�F�N�g�ƕǂ̓����蔻��
	void DeleteObjects();                //����falg��false�̃I�u�W�F�N�g���폜
	void CheckOutOfArea();               //��ʊO�ɃI�u�W�F�N�g������΍폜 
	void AddObject(AObject *object_num); //�����̃I�u�W�F�N�g�𐶐�
	int count(){return count_;}          //count�̃Q�b�^�[
	int PixelToTiles(double pixels);     //�s�N�Z���P�ʂ��^�C���P�ʂɕϊ�
	int TilesToPixels(int tiles);        //�^�C���P�ʂ��s�N�Z���P�ʂɕϊ�
	bool JudgeCircle(int x1, int y1, int r1, int x2, int y2, int r2); //�~���m�̂̓����蔻��
//	bool JudgeHitObjects(AObject p, AObjects e); //�l�p���m�̓����蔻��
	int GetMapData(double x, double y); //�`��G���A���̍��W�������ɂƂ��āA�����̃}�b�v�f�[�^��Ԃ�	
	TwoDimension GetPlayerPos();//�v���C���[�̍��W��Ԃ��֐�
};
#endif

