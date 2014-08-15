#include "Menu.h"
#include <string>

/*�I�����̕��������ʂɕ\�����āA���[�U�[�̑I��҂�(�����Ń��[�v���܂킷)�B
�I�������ꍇ�͂��̑I�����̔ԍ���Ԃ��B*/
 int Menu::Select(){
	// ���j���[���ڗv�f�����
    MenuElement_t MenuElement[MAX_SELECTION]={
            {  80,  100, "�X�e�[�W�P" }, // �^�O�̒��g�̏��ԂŊi�[�����Bx��80���Ay��100���Aname��"�Q�[���X�^�[�g"
			{  100, 150, "�X�e�[�W�Q" },
			{  100, 200, "�X�e�[�W�R" }
    };
    int SelectNum = 0; // ���݂̑I��ԍ�

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�X�V)
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0 ){

			// �v�Z�t�F�[�Y 
			
		if( key[ KEY_INPUT_DOWN ] == 1 ){ // ���L�[�������ꂽ�u�Ԃ�������
						
				SelectNum = ( SelectNum + 1 ) % MAX_SELECTION; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)
		}

		if(key[ KEY_INPUT_UP ] == 1 ){ // ��L�[�������ꂽ�u�Ԃ�������

			SelectNum = ( SelectNum + (MAX_SELECTION - 1) ) % MAX_SELECTION; // ���݂̑I�����ڂ����ɂ��炷(�t���[�v����)
		}

		if( key[ KEY_INPUT_DOWN ] == 1 || key[ KEY_INPUT_UP ] == 1 ){ // ���L�[���A��L�[�������ꂽ�u��
			for( int i=0; i<MAX_SELECTION; i++ ){              // ���j���[���ڐ��ł���������[�v����
				if( i == SelectNum ){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
					MenuElement[i].x = 80; // ���W��80�ɂ���
				} else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
					MenuElement[i].x = 100;// ���W��100�ɂ���
				}
			}
		}

		if( key[ KEY_INPUT_RETURN ] == 1){
			return SelectNum;
		}

		// �`��t�F�[�Y

		for( int i=0; i<MAX_SELECTION; i++ ){ // ���j���[���ڂ�`��
			DrawFormatString( MenuElement[i].x, MenuElement[i].y, GetColor(255,255,255), MenuElement[i].name );
		}
	}
	return -1;
}

// �L�[�̓��͏�Ԃ��X�V����
int Menu::gpUpdateKey(){
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll( tmpKey ); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			key[i]++;     // ���Z
		} else {              // ������Ă��Ȃ����
			key[i] = 0;   // 0�ɂ���
		}
	}
	return 0;
}