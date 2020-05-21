#include "Dxlib.h"
#include "main.h"
#include "GameOverScene.h"
#include "TitleScene.h"


// ゲームオーバーシーンの初期化
void GameOverInit(void)
{

}

// ゲームオーバーシーン
void GameOverScene(void)
{
	TitleInit();
}

// ゲームオーバーシーンの描画
void GameOverDraw(void)
{
	ClsDrawScreen();
	ScreenFlip();
}