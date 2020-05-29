#include "Dxlib.h"
#include "main.h"
#include "GameScen.h"
#include"Stage.h"
#include "player.h"
#include "enemy.h"
#include "GameOverScene.h"

int cen;			// 真ん中
// ゲームシーンの初期化
void GameSceneInit(void)
{

}

// ゲームシーン
void GameScene(void)
{
	/*if (CheckHitKey(KEY_INPUT_DOWN))
	{
		scnID = SCN_ID_GAMEOVER;
		GameOverInit();
	}*/
	GameSceneDraw();
}

// ゲームシーンの描画
void GameSceneDraw(void)
{
	//int sen = playerMove(cen);
	ClsDrawScreen();
	StageGameDraw();
	playerDraw();
	enemyDraw();
	ScreenFlip();
}