#include "Dxlib.h"
#include "main.h"
#include "GameScen.h"
#include"Stage.h"
#include "player.h"
#include "enemy.h"
#include "GameOverScene.h"

int cen;			// �^��
// �Q�[���V�[���̏�����
void GameSceneInit(void)
{

}

// �Q�[���V�[��
void GameScene(void)
{
	/*if (CheckHitKey(KEY_INPUT_DOWN))
	{
		scnID = SCN_ID_GAMEOVER;
		GameOverInit();
	}*/
	GameSceneDraw();
}

// �Q�[���V�[���̕`��
void GameSceneDraw(void)
{
	//int sen = playerMove(cen);
	ClsDrawScreen();
	StageGameDraw();
	playerDraw();
	enemyDraw();
	ScreenFlip();
}