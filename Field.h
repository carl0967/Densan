
#pragma once
#include "Map.h"
#include"AObject.h"
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include "ObjectManager.h"
#include <math.h>
#include <vector>
#include<typeinfo>

using namespace std;

class Field
{
//�t�B�[���h
private:
	Map* map_;                    //�}�b�v
	ObjectManager* obj_manager_; 
	int count_;                  //���Ԍv���p
	vector<AObject*> objects_;   //�S�ẴI�u�W�F�N�g�Ǘ��p
	Player* player_;              //�v���C���[�Ǘ��p
	double gravity_;             //�d�͂̒l
	int offset_;                 //�I�t�Z�b�g

	bool clear_flag;             //�N���A�t���b�O
	bool end_flag;               //�Q�[���I�[�o�[��ʗp�t���b�O
	bool menu_flag;              //���j���[��ʂɖ߂邩�ǂ�������p
	int clear_count;             //�N���A�J�E���^
	int end_count;               //�Q�[���I�[�o�[��ʗp�J�E���^�[

	int end_graphic_handle;      //�Q�[���I�[�o�[�摜
	int clear_graphic_handle;    //�Q�[���N���A�摜
	
public:
	Field(); //���R���X�g���N�^
	Field(Map* map);   //�R���X�g���N�^
	int MainLoop();  //���C�����[�v
	int GetMapData(double x, double y); //�`��G���A���̍��W�������ɂƂ��āA�����̃}�b�v�f�[�^��Ԃ�	
	int GetNextMapData(TwoDimension chara_pos,TwoDimension chara_speed,bool right); //�L�����N�^�[�����ɂ���ꏊ�̃}�b�v�f�[�^��Ԃ�
	TwoDimension GetPlayerPos();//�v���C���[�̍��W��Ԃ��֐�
	int count(){return count_;}          //count�̃Q�b�^�[
	~Field();

private:
	void Initialize();                   //����������
	void Scroll();                       //�X�N���[������
	void FallObjects();                  //�e�I�u�W�F�N�g�ɑ΂��āA�󒆂ɂ���ꍇFall���Ăяo��
	void MoveObjects();                  //�e�I�u�W�F�N�g�ɑ΂���Move���Ăяo��
	void DrawObjects();                  //�e�I�u�W�F�N�g�ɑ΂���Draw���Ăяo��
	void ThinkObjects();                 //�e�I�u�W�F�N�g�ɑ΂���
	void TouchPlayer2Objects();          //�v���C���[�A�e�ƓG�A�A�C�e���Ƃ̓����蔻��
	void TouchObjects2Wall();            //�I�u�W�F�N�g�ƕǂ̓����蔻��
	void Reset();                        //�v���C���[���S���̃��Z�b�g�֐�
	//void DeleteObjects();                //����falg��false�̃I�u�W�F�N�g���폜
	void GameOver();                     //�Q�[���I�[�o�[����
	void GameClear();                    //�Q�[���N���A����                      
	void CheckOutOfArea();               //��ʊO�̓G���E��
	void DownObjectsDie();               //��ʉ��̃I�u�W�F�N�g���E��
	void AddObject(AObject *object_num, bool isBegin); //�����̃I�u�W�F�N�g�𐶐�
	int PixelToTiles(double pixels);     //�s�N�Z���P�ʂ��^�C���P�ʂɕϊ�
	int TilesToPixels(int tiles);        //�^�C���P�ʂ��s�N�Z���P�ʂɕϊ�
	bool JudgeCircle(int x1, int y1, int r1, int x2, int y2, int r2); //�~���m�̂̓����蔻��
	bool JudgeHitCharacters(AObject* p, AObject* e); //�L�����N�^�[���m�̓����蔻��
	void FindObject(int from_y,int to_y,int from_x, int to_x);   //�`��G���A�ɓ�����enemy�̐����t���O��true�ɂ���

};

