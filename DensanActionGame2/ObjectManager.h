/*
�ǂ̃Z�����W�̃I�u�W�F�N�g���ǂ�ID�����Ǘ�����N���X
*/

#pragma once
#include "AObject.h"
#include "Map.h"

class ObjectManager{
public:
	ObjectManager();
	ObjectManager(int map_width,int map_height); //�R���X�g���N�^�B�����̓Z���̍��W
	int RegisterObject(int cell_x,int cell_y,MapChip map_chip); //�I�u�W�F�N�g��o�^����B (�o�^�����Ƃ���ID��Ԃ����ǕʂɎg��Ȃ�����)
	int GetId(int cell_x,int cell_y); //�w�肳�ꂽ���W�������l�̃I�u�W�F�N�g��ID��Ԃ�
	TwoDimension GetCellPosFromId(int id); //id�������ɂƂ��āA�Z���̍��W��Ԃ�
	~ObjectManager(); //�f�X�g���N�^
private:
	int** ids; //id��ێ����Ă������߂̂Q�����z��(�̃|�C���^)�B
	int id_counter; //id������U�邽�߂̃J�E���^�[
	int width; //���̔z��
	int height; //�c�̔z��
};