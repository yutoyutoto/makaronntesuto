#include "Dxlib.h"
#include "main.h"
#include "GameScen.h"
#include "SelectScene.h"
#include "player.h"

// �ϐ��̒�`
int charNum;
int weaCnt;
bool charFlag;
bool gCnt;

// �Z���N�g�V�[���̏�����
void SelInit(void)
{
	charNum = 0;
	weaCnt = 0;
	charFlag = false;
	gCnt = false;
}

// �Z���N�g�V�[��
void SelectScene(void)
{
	// �L�����Z���N�g
	if ((charNum == 0) && (CheckHitKey(KEY_INPUT_RIGHT)) && (charFlag == false))
	{
		charNum = 1;
	}

	if ((charNum == 1) && (CheckHitKey(KEY_INPUT_LEFT)) && (charFlag == false))
	{
		charNum = 0;
	}
	// S�L�[�ŕ���I��
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
		//// S�L�[����������Q�[�����ֈڍs
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
	else if (charNum == 1)
	{
		// �Q�[���G���A��h��
		DrawBox(536, 250, 636, 350, GetColor(0, 255, 255), true);
		DrawGraph(184, 300, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(586, 300, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
	}

	DrawString(300, 100, "�D���ȃL������I��ł�", GetColor(0, 255, 255));

	// -----����I���̕`��-----
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

	ScreenFlip();			// �o�b�N�o�b�t�@���t�����g�o�b�t�@�ɓ���ւ���
}
