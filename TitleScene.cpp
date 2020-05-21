#include "Dxlib.h"
#include "main.h"
#include "TitleScene.h"
#include "SelectScene.h"

int TitleImage;
// �^�C�g���V�[���̏�����
void TitleInit(void)
{
	TitleImage = LoadGraph("image/title.bmp");
}

// �^�C�g���V�[��
void TitleScene(void)
{
	if ((spacekeyFlag == true) && (spacekeyFlagOld == false))
	{
		// �X�y�[�X�L�[����������Z���N�g�V�[���Ɉڍs
		scnID = SCN_ID_CHARSEL;
		SelectScene();
	}
	TitleDraw();
}

// �^�C�g���V�[���̕`��
void TitleDraw(void)
{
	//ClsDrawScreen();
	DrawGraph(0, 0, TitleImage, true);
	if ((flamCnt / 40) % 2 == 0)
	{
		DrawString(250, 400, "�o�k�d�`�r�d�@�r�o�`�b�d�@�j�d�x", GetColor(0, 255, 255));
	}
	flamCnt++;
	ScreenFlip();
}