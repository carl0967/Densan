#pragma once

/*
�u���́v�̒��ۃN���X
*/

class AObject{
public:
	AObject(double ax,double ay);  
	void Move();                  //���g�̃X�s�[�h���ړ�����
	void Draw(int offset);   //offset���g���Ď��g�̕`��ʒu���Z�o���ĕ`�悷��
	 void Think();  //���g�̃X�s�[�h�𑀍삵�čs�������߂�
	void TouchedWall();   //�ǂƓ��������Ƃ��ɌĂ΂��
	void Fall(double g);  // �����̏d�͕�������

protected:
	int made_time;   //�������ꂽ���ԁiField����݂��j
	static int graphic_handle;  //�ǂ̃������ɉ摜���ǂݍ��܂�Ă��邩
	double x;   //x���W
	double y;  //y���W
	bool alive; //�������Ă����true
	double speed_x; //x���̃X�s�[�h
	double speed_y; //y���̃X�s�[�h
	int width; //�I�u�W�F�N�g�̕� (�����蔻��p)
	int height; //�I�u�W�F�N�g�̍���
	bool right; //������\���B�E�����Ȃ�true�B�������Ȃ�false
	bool aerial; //�󒆂ɂ���Ȃ�true�B�n�ʂɐڂ��Ă���Ȃ�false

};