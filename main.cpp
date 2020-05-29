//
// TestProject
//   by 若永優斗
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


//変数
SCN_ID scnID;					// ｼｰﾝ管理
int gameCounte;

bool spacekeyFlag;				// スペースキーの状態	
bool spacekeyFlagOld;			// 1フレーム前のスペースキーの状態

int flamCnt;


// ========WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// システム処理
	SetWindowText("TestProject");
	// システム処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	//---------　グラフィックの登録　----------
	gameCounte = 0;

	//---------　変数の初期化 ---------
	SisInit();
	//--------- ゲームループ　---------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// メイン処理
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
	// 返り値用変数
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
