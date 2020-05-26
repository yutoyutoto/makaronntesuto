#include "Dxlib.h"
#include "main.h"
#include "GameScen.h"
#include "SelectScene.h"
#include "player.h"

// 変数の定義
int charNum;
int weaCnt;
bool charFlag;
bool gCnt;

// セレクトシーンの初期化
void SelInit(void)
{
	charNum = 0;
	weaCnt = 0;
	charFlag = false;
	gCnt = false;
}

// セレクトシーン
void SelectScene(void)
{
	// キャラセレクト
	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_RIGHT)) && (charFlag == false))
	{
		charNum = 1;
	}

	if ((charNum == 1) && (CheckHitKey(KEY_INPUT_LEFT)) && (charFlag == false))
	{
		charNum = 0;
	}
	// Sキーで武器選択
	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_S)) && (weaCnt == 0))
	{
		weaCnt = 1;
		charFlag = true;
		gCnt = true;
	}

	if ((charNum == 1) && (CheckHitKey(KEY_INPUT_S)))
	{
		weaCnt = 3;
		charFlag = true;
		gCnt = true;
		//// Sキーを押したらゲーム中へ移行
		//scnID = SCN_ID_GAME;
		//GameScene();
	}

	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_DOWN)) && (charFlag == true))
	{
		weaCnt = 2;
	}

	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_UP)) && (charFlag == true))
	{
		weaCnt = 1;
	}

	if ((CheckHitKey(KEY_INPUT_SPACE)) && (gCnt == true))
	{
		scnID = SCN_ID_GAME;
		GameScene();
	}
	SelDraw();
}

// セレクトシーンの描画
void SelDraw(void)
{
	ClsDrawScreen();		// 画面消去

	playerAnimCnt++;
	// キャラ選択
	if (charNum == 0)
	{
		// ゲームエリアを塗る
		DrawBox(134, 250, 234, 350, GetColor(0, 255, 255), true);
		DrawGraph(184, 300, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(586, 300, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
	}
	else if (charNum == 1)
	{
		// ゲームエリアを塗る
		DrawBox(536, 250, 636, 350, GetColor(0, 255, 255), true);
		DrawGraph(184, 300, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(586, 300, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
	}

	DrawString(300, 100, "好きなキャラを選んでね", GetColor(0, 255, 255));

	// -----武器選択の描画-----
	if (weaCnt == 1)
	{
		DrawBox(184, 350, 250, 400, GetColor(0, 255, 255), true);
		DrawGraph(184, 350, kenImage, true);
		DrawGraph(184, 400, jyuuImage, true);
	}
	else if (weaCnt == 2)
	{
		DrawBox(184, 400, 250, 500, GetColor(0, 255, 255), true);
		DrawGraph(184, 350, kenImage, true);
		DrawGraph(184, 400, jyuuImage, true);
	}
	else if (weaCnt == 3)
	{
		DrawGraph(0, 0, tueImage, true);
	}

	ScreenFlip();			// バックバッファをフロントバッファに入れ替える
}
