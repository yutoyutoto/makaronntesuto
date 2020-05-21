#include "Dxlib.h"
#include "main.h"
//#include "GameScene.h"
#include "SelectScene.h"
#include "player.h"

// �ϐ��̒�`
int charNum;
int weapon;
int weaCnt;

// �Z���N�g�V�[���̏�����
void SelInit(void)
{
	charNum = 0;
	weapon = 0;
	weaCnt = 0;
}

// �Z���N�g�V�[��
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
		// S�L�[����������Q�[�����ֈڍs
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
		// S�L�[����������Q�[�����ֈڍs
		scnID = SCN_ID_GAME;
		GameMain();
	}
	SelDraw();
}

// �Z���N�g�V�[���̕`��
void SelDraw(void)
{
	ClsDrawScreen();		// ��ʏ���

	playerAnimCnt++;
	// �L�����I��
	if (charNum == 0)
	{
		// �Q�[���G���A��h��
		DrawBox(134, 250, 234, 350, GetColor(0, 255, 255), true);
		DrawGraph(184, 300, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(586, 300, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
	}
	else
	{
		// �Q�[���G���A��h��
		DrawBox(536, 250, 636, 350, GetColor(0, 255, 255), true);
		DrawGraph(184, 300, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(586, 300, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
	}
	DrawString(300, 100, "�D���ȃL������I��ł�", GetColor(0, 255, 255));

	// -----����I��-----
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

	ScreenFlip();			// �o�b�N�o�b�t�@���t�����g�o�b�t�@�ɓ���ւ���
}
