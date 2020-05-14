//
// TestProject
//   by ��i�D�l
//
#include "Dxlib.h"
#include "main.h"
#include "Stage.h"

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
// �Q�[�����C��
void GameMain(void)
{
	GameDraw();
}
//�@������
bool SystemInit(void)
{
	StageGameDraw();
	return false;
}
//�@�������V�[��
void InitScene(void)
{

}
//�@�^�C�g���V�[��
void TitleScene(void)
{

}
//�@�^�C�g���`��
void TitleDraw(void)
{

}
//�@�Q�[���I�[�o�[�V�[��
void GameOverScene(void)
{

}
//�@�Q�[���I�[�o�[�`��
void GameOverDraw(void)
{

}
// ���U���g�V�[��
void RizartScene(void)
{

}
// ���U���g�`��
void RizartDraw(void)
{

}
//�@�Q�[���`��
void GameDraw(void)
{
	StageGameDraw();
}
