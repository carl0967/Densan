#define MAX_SELECTION 3//�I�����̌�
#pragma once
#include <dxlib.h>
#include <string>
using namespace std;

/*���j���[��ʂ̃N���X*/

class Menu{
private:
	typedef struct{
        int x, y;       // ���W�i�[�p�ϐ�
		char picName[128];// ���ږ��摜�i�[�p�ϐ�
        char fileName[128]; // ���ږ��i�[�p�ϐ�
	} MenuElement_t ;
	int key[256]; // �L�[��������Ă���t���[�������i�[����

public:
	void Start();//�^�C�g����ʂ̕\��
	string Select();//���[�U�[�̑I��
	int gpUpdateKey();//�L�[�̓��͏��
};
