//
// TestProject
//   by ��i�D�l
//
#include "Dxlib.h"
#include "main.h"
#include "Stage.h"
#include "enemy.h"
#include "player.h"

//�ϐ�

//�ϐ�
SCN_ID scnID;					// ��݊Ǘ�
int gameCounte;

bool spacekeyFlag;				// �X�y�[�X�L�[�̏��	
bool spacekeyFlagOld;			// 1�t���[���O�̃X�y�[�X�L�[�̏��

//int jyu;
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
	SystemInit();
	//--------- �Q�[�����[�v�@---------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen(); // ��ʏ���

		// ���C������
		GameMain();
		gameCounte++;
		ScreenFlip(); // ����ʂ�\��ʂɏu�ԃR�s�[

		if(CheckHitKey(KEY_INPUT_RIGHT))
		{
			mapPos.x += 10;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			mapPos.x -= 10;
		}
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
	StageSystemInit();
	playerInit();
	EnemyInt();
	//jyu = LoadGraph("image/jyuu2.bmp");
	return true;
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
	//ScreenFlip();
	
	StageGameDraw();
	EnemyDraw();
	playerDraw();
	//ClsDrawScreen();

	
	//DrawGraph(30, 20, jyu, true);
}
