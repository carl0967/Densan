#define MAX_SELECTION 3//�I�����̌�
#pragma once
#include <dxlib.h>
#include <string>
using namespace std;

/*���j���[��ʂ̃N���X*/

class Menu{
private:
	string selection_array;//�I�����̕�����̔z��
	typedef struct{
        int x, y;       // ���W�i�[�p�ϐ�
        char name[128]; // ���ږ��i�[�p�ϐ�
	} MenuElement_t ;
	int key[256]; // �L�[��������Ă���t���[�������i�[����

public:
	void Start();//�^�C�g����ʂ̕\��
	int Select();//���[�U�[�̑I��
	int gpUpdateKey();//�L�[�̓��͏��
};
