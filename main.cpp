//
// TestProject
//   by ��i�D�l
//
#include "Dxlib.h"
#include "main.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "GameScen.h"
#include "player.h"
#include "enemy.h"
#include "GameOverScene.h"
#include "Stage.h"


//�ϐ�
SCN_ID scnID;					// ��݊Ǘ�
int gameCounte;

bool spacekeyFlag;				// �X�y�[�X�L�[�̏��	
bool spacekeyFlagOld;			// 1�t���[���O�̃X�y�[�X�L�[�̏��

int flamCnt;


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
	SisInit();
	//--------- �Q�[�����[�v�@---------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ���C������
		/*if (scnIDOld != scnID)
		{
			flamCnt = 0;
		}
		scnIDOld = scnID;*/
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			mapPos.x += 30;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			mapPos.x -= 30;
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
			GameScene();
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
	}
	return 0;
	DxLib_End();
}

void SisInit(void)
{
	// �Ԃ�l�p�ϐ�
	bool rtnFlag = true;

	spacekeyFlag = false;
	spacekeyFlagOld = false;
	playerInit();
	enemyInit();
	SelInit();
	TitleInit();
	StageSystemInit();
	scnID = SCN_ID_TITLE;
}

void GetKeyState(void)
{
	spacekeyFlagOld = spacekeyFlag;
	spacekeyFlag = (bool)CheckHitKey(KEY_INPUT_SPACE);
}
