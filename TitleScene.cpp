#include "Dxlib.h"
#include "main.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "GameScen.h"

// 変数の定義
// イメージ用
int TitleImage;

// タイトルシーンの初期化
void TitleInit(void)
{
	bool rtnFlag = true;
	TitleImage = LoadGraph("Image/Title.bmp");
	if (TitleImage == -1)
	{
		AST();
		rtnFlag = false;
	}
}

// タイトルシーン
void TitleScene(void)
{
	if ((spacekeyFlag == true) && (spacekeyFlagOld == false))
	{
		// スペースキーを押したらセレクトシーンに移行
		scnID = SCN_ID_CHARSEL;
		SelectScene();
	}
	flamCnt = 0;
	TitleDraw();
}

// タイトルシーンの描画
void TitleDraw(void)
{
	ClsDrawScreen();
	DrawGraph(0, 0, TitleImage, true);
	if ((flamCnt / 40) % 2 == 0)
	{
		DrawString(250, 400, "ＰＬＥＡＳＥ　ＳＰＡＣＥ　ＫＥＹ", GetColor(0, 255, 255));
	}
	flamCnt++;
	ScreenFlip();
}