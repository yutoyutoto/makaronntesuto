#include <math.h>
#include "Dxlib.h"
#include "main.h"
#include "SelectScene.h"
#include "player.h"

// �ϐ��̒�`
Player player;
Pos playerSpeed;

// �C���[�W�p
int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
int kenImage;
int jyuuImage;
int tueImage;
int gumiImage;
int eriImage;

int playerAnimCnt;		// �A�j���[�V�����̑���

int keyFlag;

int Gravity;
int jumpCnt;
int jump2Cnt;


// �v���C���[�̏�����
void playerInit(void)
{
	bool rtnFlag = true;

	if (LoadDivGraph("Image/murabito2.bmp", ANIM_IMAGE_MAX, ANIM_IMAGE_MAX, 1,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[0][0]) == -1)
	{
		AST();
		rtnFlag = false;
	}


	if (LoadDivGraph("Image/hime2.bmp", ANIM_IMAGE_MAX, ANIM_IMAGE_MAX, 1,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[1][0]) == -1)
	{
		AST();
		rtnFlag = false;
	}

	kenImage = LoadGraph("Image/ken.bmp");
	if (kenImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	jyuuImage = LoadGraph("Image/jyuu1.bmp");
	if (jyuuImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	tueImage = LoadGraph("Image/tue2.bmp");
	if (tueImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	gumiImage = LoadGraph("Image/gumi.bmp");
	if (gumiImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	eriImage = LoadGraph("Image/eri.bmp");
	if (eriImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	player.pos.x = 0;
	player.pos.y = 500;
	keyFlag = 0;

	playerSpeed.x = 5;
	playerSpeed.y = 30;
	Gravity = 2;
	jumpCnt = 0;
	jump2Cnt = 0;
}


// �v���C���[�̓���
void playerMove(void)
{
	// �E�ړ�
	player.pos.x += 1;
	// 1��ڂ̃W�����v�̏���
	if (CheckHitKey(KEY_INPUT_W))
	{
		keyFlag++;
	}
	if (keyFlag > 0)
	{
		player.pos.x += playerSpeed.x;
		player.pos.y = player.pos.y - playerSpeed.y + Gravity * jumpCnt;
		jumpCnt++;
	}
	if (player.pos.y >= 500)
	{
		jumpCnt = 0;
		keyFlag = 0;
	}

	// 2��ڂ̃W�����v����
	if (CheckHitKey(KEY_INPUT_A))
	{
		keyFlag++;
	}
	/*if (keyFlag > 0)
	{
		player.pos.x += playerSpeed.x;
		player.pos.y = player.pos.y - playerSpeed.y + Gravity * jumpCnt;
		jump2Cnt++;
	}*/
	if (player.pos.y >= 500)
	{
		jump2Cnt = 0;
		keyFlag = 0;
	}
	// �J��Ԃ�
	if (player.pos.x >= SCREEN_SIZE_X)
	{
		player.pos.x = 0;
	}
	// ���̉�]

}

// �v���C���[�̕`��
void playerDraw(void)
{
	//ClsDrawScreen();		// ��ʏ���
	/*if (playerAnimCnt == 4)
	{
		playerAnimCnt = 0;
	}*/
	playerAnimCnt++;
	if (charNum == 0)
	{
		DrawGraph(player.pos.x, player.pos.y, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		//DrawGraph(player.pos.x + 20, player.pos.y - 10, kenImage, true);
		DrawGraph(player.pos.x + 20, player.pos.y, jyuuImage, true);
	}
	else
	{
		DrawGraph(player.pos.x, player.pos.y, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(player.pos.x, player.pos.y - 5, tueImage, true);
	}
	DrawGraph(0, 0, eriImage, true);
	playerMove();
	ScreenFlip();			// �o�b�N�o�b�t�@���t�����g�o�b�t�@�ɓ���ւ���
}
