//
// TestProject
//   by ��i�D�l
//
#include "Dxlib.h"
#include "main.h"
#include "Stage.h"
#include "enemy.h"
#include "player.h"
#include"GameOverScene.h"
#include"TitleScene.h"
#include"SelectScene.h"

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
		TitleScene();
		if(CheckHitKey(KEY_INPUT_RIGHT))
		{
			mapPos.x += 10;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			mapPos.x -= 10;
		}
	}

	GetKeyState();

	switch (scnID)
	{
	case SCN_ID_TITLE:
		TitleScene();
		break;
	case SCN_ID_CHARSEL:
		SelectScene();
		break;
	case SCN_ID_GAME:
		GameMain();
		break;
	case SCN_ID_GAMEOVER:
		GameOverScene();
		break;
	default:
		AST();
		break;
	}
	//TitleInit();
	//GameMain();

	gameCounte++;
	ScreenFlip();
	return 0;
	DxLib_End();
}
// �Q�[�����C��
void GameMain(void)
{
	GameDraw();
}

void GetKeyState(void)
{
	spacekeyFlagOld = spacekeyFlag;
	spacekeyFlag = (bool)CheckHitKey(KEY_INPUT_SPACE);
}

//�@������
bool SystemInit(void)
{

	// �Ԃ�l�p�ϐ�
	bool rtnFlag = true;
	StageSystemInit();
	playerInit();
	TitleInit();
	GameOverInit();
	EnemyInt();

	spacekeyFlag = false;
	spacekeyFlagOld = false;
	SelInit();
	scnID = SCN_ID_TITLE;
	//jyu = LoadGraph("image/jyuu2.bmp");
	return true;
}
//�@�������V�[��
void InitScene(void)
{

}



//�@�Q�[���`��
void GameDraw(void)
{
	//ScreenFlip();
	TitleDraw();
	StageGameDraw();
	EnemyDraw();
	playerDraw();
	GameOverDraw();
	//ClsDrawScreen();

	
	//DrawGraph(30, 20, jyu, true);
}
