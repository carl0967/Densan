
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

	bool menu_flag;              //���j���[��ʂɖ߂邩�ǂ�������p
	int wait_count_;

	int end_graphic_handle;      //�Q�[���I�[�o�[�摜
	int clear_graphic_handle;    //�Q�[���N���A�摜

	int BGM;                     //BGM�p
	
public:
	Field(); //���R���X�g���N�^
	Field(Map* map);   //�R���X�g���N�^
	int MainLoop();  //���C�����[�v	
	bool IsNextMapDataAWall(TwoDimension chara_pos, TwoDimension chara_speed, bool right);
	TwoDimension GetPlayerPos();//�v���C���[�̍��W��Ԃ��֐�
	int count(){return count_;}          //count�̃Q�b�^�[
	Player* player(){return player_;} //�v���C���[��Ԃ�
	~Field(); //�f�X�g���N�^

private:
	void Initialize();                   //����������
	void Scroll();                       //�X�N���[������
	void FallObjects();                  //�e�I�u�W�F�N�g�ɑ΂��āA�󒆂ɂ���ꍇFall���Ăяo��
	void MoveObjects();                  //�e�I�u�W�F�N�g�ɑ΂���Move���Ăяo��
	void DrawObjects();                  //�e�I�u�W�F�N�g�ɑ΂���Draw���Ăяo��
	void ThinkObjects();                 //�e�I�u�W�F�N�g�ɑ΂���
	void TouchPlayerToObjects();          //�v���C���[�A�e�ƓG�A�A�C�e���Ƃ̓����蔻��
	void TouchObjectsToWall();            //�I�u�W�F�N�g�ƕǂ̓����蔻��
	void BulletTouchWall();                //�ǂƒe�̓����蔻��
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

