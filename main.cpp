//
// TestProject
//   by ��i�D�l
//
#include "Dxlib.h"
#include "main.h"

//�ϐ�
int gameCounte;

// ========WinMain�֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �V�X�e������
	SetWindowText("TestProject");
	// �V�X�e������
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	//---------�@�O���t�B�b�N�̓o�^�@----------
	gameCounte = 0;

	//---------�@�ϐ��̏����� ---------

	//--------- �Q�[�����[�v�@---------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen(); // ��ʏ���

		// ���C������
		GameMain();

		gameCounte++;
		ScreenFlip(); // ����ʂ�\��ʂɏu�ԃR�s�[

	}
	return 0;
	DxLib_End();
}

void GameMain(void)
{
	GameDraw();
}
void GameDraw(void)
{

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "�킩�Ȃ���HP -%d",gameCounte);
}
