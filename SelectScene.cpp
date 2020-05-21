#include "Dxlib.h"
#include "main.h"
//#include "GameScene.h"
#include "SelectScene.h"
#include "player.h"

// 変数の定義
int charNum;
int weapon;
int weaCnt;

// セレクトシーンの初期化
void SelInit(void)
{
	charNum = 0;
	weapon = 0;
	weaCnt = 0;
}

// セレクトシーン
void SelectScene(void)
{
	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_RIGHT)))
	{
		charNum = 1;
	}

	if ((charNum == 1) && (CheckHitKey(KEY_INPUT_LEFT)))
	{
		charNum = 0;
	}

	if ((charNum == 1) && (CheckHitKey(KEY_INPUT_S)))
	{
		// Sキーを押したらゲーム中へ移行
		scnID = SCN_ID_GAME;
		GameMain();
	}

	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_S)))
	{
		weaCnt = 1;
	}

	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_DOWN)))
	{
		weaCnt = 2;
	}

	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_UP)))
	{
		weaCnt = 1;
	}

	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_S)) && (weaCnt == 0))
	{
		// Sキーを押したらゲーム中へ移行
		scnID = SCN_ID_GAME;
		GameMain();
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
	else
	{
		// ゲームエリアを塗る
		DrawBox(536, 250, 636, 350, GetColor(0, 255, 255), true);
		DrawGraph(184, 300, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(586, 300, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
	}
	DrawString(300, 100, "好きなキャラを選んでね", GetColor(0, 255, 255));

	// -----武器選択-----
	if (weaCnt == 1)
	{
		DrawBox(184, 350, 250, 400, GetColor(0, 255, 255), true);
		DrawGraph(184, 350, kenImage, true);
		DrawGraph(184, 400, tueImage, true);
	}
	else if (weaCnt == 2)
	{
		DrawBox(184, 400, 250, 500, GetColor(0, 255, 255), true);
		DrawGraph(184, 350, kenImage, true);
		DrawGraph(184, 400, tueImage, true);
	}

	ScreenFlip();			// バックバッファをフロントバッファに入れ替える
}
