//
// TestProject
//   by 若永優斗
//
#include "Dxlib.h"
#include "main.h"

//変数
int gameCounte;

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

	//--------- ゲームループ　---------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen(); // 画面処理

		// メイン処理
		GameMain();

		gameCounte++;
		ScreenFlip(); // 裏画面を表画面に瞬間コピー

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

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "わかながのHP -%d",gameCounte);
}
