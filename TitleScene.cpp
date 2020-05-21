#include "Dxlib.h"
#include "main.h"
#include "TitleScene.h"
#include "SelectScene.h"

int TitleImage;
// タイトルシーンの初期化
void TitleInit(void)
{
	TitleImage = LoadGraph("image/title.bmp");
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
	TitleDraw();
}

// タイトルシーンの描画
void TitleDraw(void)
{
	//ClsDrawScreen();
	DrawGraph(0, 0, TitleImage, true);
	if ((flamCnt / 40) % 2 == 0)
	{
		DrawString(250, 400, "ＰＬＥＡＳＥ　ＳＰＡＣＥ　ＫＥＹ", GetColor(0, 255, 255));
	}
	flamCnt++;
	ScreenFlip();
}