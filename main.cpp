//
// TestProject
//   by 若永優斗
//
#include "Dxlib.h"
#include "main.h"
#include "Stage.h"
#include "enemy.h"
#include "player.h"

//変数
int gameCounte;
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
// ゲームメイン
void GameMain(void)
{
	GameDraw();
}
//　初期化
bool SystemInit(void)
{
	StageSystemInit();
	PlayerInit();
	EnemyInt();
	//jyu = LoadGraph("image/jyuu2.bmp");
	return true;
}
//　初期化シーン
void InitScene(void)
{

}
//　タイトルシーン
void TitleScene(void)
{

}
//　タイトル描画
void TitleDraw(void)
{

}
//　ゲームオーバーシーン
void GameOverScene(void)
{

}
//　ゲームオーバー描画
void GameOverDraw(void)
{

}
// リザルトシーン
void RizartScene(void)
{

}
// リザルト描画
void RizartDraw(void)
{

}
//　ゲーム描画
void GameDraw(void)
{
	StageGameDraw();
	EnemyDraw();
	PlayerDraw();
	//DrawGraph(30, 20, jyu, true);
}
