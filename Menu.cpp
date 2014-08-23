#include "Menu.h"

/*�^�C�g����ʂ̕\�����s���BEnter�L�[�����͂��ꂽ��I����ʂɈڂ�B*/
void Menu::Start(){
	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�X�V)
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0 ){

		//�v�Z�t�F�[�Y

		if( key[ KEY_INPUT_RETURN ] == 1){
			break;
		}

		// �`��t�F�[�Y

		// ���j���[���ڂ�`��
		LoadGraphScreen(0,20,"�摜/title.png",TRUE);

		DrawFormatString( 320, 300, GetColor(255,255,255), "Press the Enter Key!");

	}
}

/*�I�����̕��������ʂɕ\�����āA���[�U�[�̑I��҂�(�����Ń��[�v���܂킷)�B
�I�������ꍇ�͂��̑I�����̔ԍ���Ԃ��B*/

string Menu::Select(){
	// ���j���[���ڗv�f�����
	

	//�摜��`�悷��
    MenuElement_t MenuElement[MAX_SELECTION]={
            {  80,100, "�摜/stage1.png", "�}�b�v/map1.txt"}, //x���W�Ay���W�A�摜���A�t�@�C�����̏��ԂŊi�[�����B
			{  50,150, "�摜/stage2.png", "�}�b�v/map2.txt"},
			{  50,200, "�摜/stage3.png", "�}�b�v/map3.txt"}
    };

    int SelectNum = 0; // ���݂̑I��ԍ�

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�X�V)
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0 ){

		// �v�Z�t�F�[�Y 
			
		if( key[ KEY_INPUT_DOWN ] == 1 ){ // ���L�[�������ꂽ�u�Ԃ�������
						
			SelectNum = ( SelectNum + 1 ) % MAX_SELECTION; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)
			PlaySoundFile( "����/select_sound.wav" , DX_PLAYTYPE_NORMAL ) ;//�I���������ꂽ��A�I�������Đ�
		}

		if(key[ KEY_INPUT_UP ] == 1 ){ // ��L�[�������ꂽ�u�Ԃ�������

			SelectNum = ( SelectNum + (MAX_SELECTION - 1) ) % MAX_SELECTION; // ���݂̑I�����ڂ����ɂ��炷(�t���[�v����)
			PlaySoundFile( "����/select_sound.wav" , DX_PLAYTYPE_NORMAL ) ;//�I���������ꂽ��A�I�������Đ�
		}

		if( key[ KEY_INPUT_DOWN ] == 1 || key[ KEY_INPUT_UP ] == 1 ){ // ���L�[���A��L�[�������ꂽ�u��
			for( int i=0; i<MAX_SELECTION; i++ ){              // ���j���[���ڐ��ł���������[�v����
				if( i == SelectNum ){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
					MenuElement[i].x = 80; // ���W��80�ɂ���
				} else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
					MenuElement[i].x = 50;// ���W��50�ɂ���
				}
			}
		}

		if( key[ KEY_INPUT_RETURN ] == 1){
			PlaySoundFile( "����/decision_sound.wav" , DX_PLAYTYPE_NORMAL ) ;//���艹���Đ�
			for( int i=0; i<MAX_SELECTION; i++ ){              // ���j���[���ڐ��ł���������[�v����
				if( i == SelectNum ){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
					return MenuElement[i].fileName;
				}
			}
		}

		// �`��t�F�[�Y
		LoadGraphScreen(20,10,"�摜/select_title.png",TRUE);

		for( int i=0; i<MAX_SELECTION; i++ ){ // ���j���[���ڂ�`��
			LoadGraphScreen(MenuElement[i].x,MenuElement[i].y,MenuElement[i].picName,TRUE);
			//�I�𒆂̑I�����ڂȂ�
			if(i==SelectNum){
				//�I���{�^���̉摜��\��
				LoadGraphScreen(MenuElement[i].x-30,MenuElement[i].y+10,"�摜/selection_key.png",TRUE);
				
			}
		}
	}
	return "";
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