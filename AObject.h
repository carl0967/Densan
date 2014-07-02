#pragma once

class AObject{
public:
	AObject(double x,double y);  
	void Move();                  //���g�̃X�s�[�h���ړ�����
	void Draw(int offset);   //offset���g���Ď��g�̕`��ʒu���Z�o���ĕ`�悷��
	virtual void Think()=0;  //���g�̃X�s�[�h�𑀍삵�čs�������߂�
	void TouchedWall();   //�ǂƓ��������Ƃ��ɌĂ΂��
	void Fall(double g);  // �����̏d�͕�������

protected:
	int made_time;   //�������ꂽ���ԁiField����݂��j
	static int graphic_handle;  //�ǂ̃������ɉ摜���ǂݍ��܂�Ă��邩
	int x;   //x���W
	int y;  //y���W
	int alive; //�������Ă����true
	int speed_x; //x���̃X�s�[�h
	int speed_y; //y���̃X�s�[�h
	int width; //�I�u�W�F�N�g�̕� (�����蔻��p)
	int height; //�I�u�W�F�N�g�̍���
	bool right; //������\���B�E�����Ȃ�true�B�������Ȃ�false
	bool aerial; //�󒆂ɂ���Ȃ�true�B�n�ʂɐڂ��Ă���Ȃ�false

}