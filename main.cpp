//
// TestProject
//   by 若永優斗
//
#include "Dxlib.h"
#include "main.h"
#include "Stage.h"
#include "enemy.h"
#include "player.h"
#include"GameOverScene.h"
#include"TitleScene.h"
#include"SelectScene.h"

//変数

//変数
SCN_ID scnID;					// ｼｰﾝ管理
int gameCounte;

bool spacekeyFlag;				// スペースキーの状態	
bool spacekeyFlagOld;			// 1フレーム前のスペースキーの状態

//int jyu;
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
	SystemInit();
	//--------- ゲームループ　---------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen(); // 画面処理

		// メイン処理
		GameMain();
		gameCounte++;
		ScreenFlip(); // 裏画面を表画面に瞬間コピー
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
// ゲームメイン
void GameMain(void)
{
	GameDraw();
}

void GetKeyState(void)
{
	spacekeyFlagOld = spacekeyFlag;
	spacekeyFlag = (bool)CheckHitKey(KEY_INPUT_SPACE);
}

//　初期化
bool SystemInit(void)
{

	// 返り値用変数
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
//　初期化シーン
void InitScene(void)
{

}



//　ゲーム描画
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
