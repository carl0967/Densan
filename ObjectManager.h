/*
�ǂ̃Z�����W�̃I�u�W�F�N�g���ǂ�ID�����Ǘ�����N���X
*/

#pragma once

class ObjectManager{
public:
	ObjectManager();
	ObjectManager(int map_width,int map_height); //�R���X�g���N�^�B�����̓Z���̍��W
	int FindObject(int cell_x,int cell_y); //�I�u�W�F�N�g���݂����Ƃ��ɌĂяo���Bid��Ԃ�
	int GetId(int cell_x,int cell_y); //�e�X�g�p�֐�
	~ObjectManager(); //�f�X�g���N�^�B������
private:
	int** ids; //id��ێ����Ă������߂̂Q�����z��(�̃|�C���^)�B
	int id_counter; //id������U�邽�߂̃J�E���^�[
};