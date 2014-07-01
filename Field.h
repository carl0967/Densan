# ifndef FIELD_H
# define FIELD_H
#pragma once
using namespace std;

class Field
{
//�t�B�[���h
private:
	Map map;                    //�}�b�v
	int count;                  //���Ԍv���p
	vector<int> objects;    //�S�ẴI�u�W�F�N�g�Ǘ��p
	double gravity;             //�d�͂̒l

//���\�b�h
public:
	Field(void);      //�R���X�g���N�^
	bool MainLoop();  //���C�����[�v

private:
	void Scroll();                  //�X�N���[������
	void FallObjects();             //�e�I�u�W�F�N�g�ɑ΂��āA�󒆂ɂ���ꍇFall���Ăяo��
	void MoveObjects();             //�e�I�u�W�F�N�g�ɑ΂���Move���Ăяo��
	void DrawObjects();             //�e�I�u�W�F�N�g�ɑ΂���Draw���Ăяo��
	void ThinkObjects();            //�e�I�u�W�F�N�g�ɑ΂���
	void TouchPlayer2Objects();     //�v���C���[�A�e�ƓG�A�A�C�e���Ƃ̓����蔻��
	void TouchObjects2Wall();       //�I�u�W�F�N�g�ƕǂ̓����蔻��
	void DeleteObjects();           //����falg��false�̃I�u�W�F�N�g���폜
	void CheckOutOfArea();          //��ʊO�ɃI�u�W�F�N�g������΍폜 
	void AddObject(int object_num); //�����̃I�u�W�F�N�g�𐶐�
	
};
#endif
