#include <math.h>
#include "Dxlib.h"
#include "main.h"
#include "SelectScene.h"
#include "player.h"
#include "enemy.h"

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

	// ���l
	if (LoadDivGraph("Image/murabito2.bmp", ANIM_IMAGE_MAX, ANIM_IMAGE_MAX, 1,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[0][0]) == -1)
	{
		AST();
		rtnFlag = false;
	}

	// �P
	if (LoadDivGraph("Image/hime2.bmp", ANIM_IMAGE_MAX, ANIM_IMAGE_MAX, 1,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[1][0]) == -1)
	{
		AST();
		rtnFlag = false;
	}

	// ��
	kenImage = LoadGraph("Image/ken.bmp");
	if (kenImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	// �e
	jyuuImage = LoadGraph("Image/jyuu1.bmp");
	if (jyuuImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	// ��
	tueImage = LoadGraph("Image/tue3.bmp");
	if (tueImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	// �O�~
	gumiImage = LoadGraph("Image/gumi.bmp");
	if (gumiImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	// �G���N�T�[
	eriImage = LoadGraph("Image/eri.bmp");
	if (eriImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	player.pos.x = 80;
	player.pos.y = 545;
	keyFlag = 0;

	playerSpeed.y = 35;
	Gravity = 2;
	jumpCnt = 0;
	jump2Cnt = 0;
	/*playerSpeed.y = 4;
	Gravity = 10;
	jumpCnt = 8;
	jump2Cnt = 0;*/
}


// �v���C���[�̓���
void playerMove(void)
{
	// 1��ڂ̃W�����v�̏���
	if (CheckHitKey(KEY_INPUT_W))
	{
		keyFlag++;
	}
	if (keyFlag > 0)
	{
		player.pos.y = player.pos.y - playerSpeed.y + Gravity * jumpCnt;
		jumpCnt++;
	}
	if (player.pos.y >= 545)
	{
		jumpCnt = 0;
		keyFlag = 0;
	}
	/*if (CheckHitKey(KEY_INPUT_W))
	{
		keyFlag = 1;
	}

	if (keyFlag == 1)
	{
		player.pos.y = player.pos.y - jumpCnt;
		//jumpCnt+= 1;
	}

	if (player.pos.y < 250)
	{
		keyFlag = 2;
		//jumpCnt = 1;
	}

	if (keyFlag == 2)
	{
		//jumpCnt += 3;
		player.pos.y = player.pos.y + jumpCnt;
	}
	if (player.pos.y > 545)
	{
		player.pos.y = 545;
		keyFlag = 0;
	}*/



	// 2��ڂ̃W�����v����


	// ���̉�]

}

// �v���C���[�̕`��
void playerDraw(void)
{
	playerAnimCnt++;
	if ((charNum == 0) && (weaCnt == 1))
	{
		DrawGraph(player.pos.x, player.pos.y, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(player.pos.x + 20, player.pos.y - 10, kenImage, true);
	}
	else if ((charNum == 0) && (weaCnt == 2))
	{
		DrawGraph(player.pos.x, player.pos.y, playerImage[CHAR_ID_MURABITO][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(player.pos.x + 20, player.pos.y, jyuuImage, true);
	}
	else
	{
		DrawGraph(player.pos.x, player.pos.y, playerImage[CHAR_ID_HIME][(playerAnimCnt / ANIM_SPEED) % 4], true);
		DrawGraph(player.pos.x + 15, player.pos.y - 5, tueImage, true);
	}
	playerMove();
	enemyObj();
}

// �G�l�~�[�Ƃ̓����蔻��
void enemyObj(void)
{
	// �����̓����蔻��
	if ((player.pos.x < maou.pos.x + ENEMY_SIZE_X) &&
		(player.pos.x + PLAYER_SIZE_X > maou.pos.x) &&
		(player.pos.y < maou.pos.y + ENEMY_SIZE_Y) &&
		(player.pos.y + PLAYER_SIZE_Y > maou.pos.y))
	{
		maouFlag = false;
		maouCnt++;
	}

	// ���C�h�̓����蔻��
	if ((player.pos.x < meid.pos.x + ENEMY_SIZE_X) &&
		(player.pos.x + PLAYER_SIZE_X > meid.pos.x) &&
		(player.pos.y < meid.pos.y + ENEMY_SIZE_Y) &&
		(player.pos.y + PLAYER_SIZE_Y > meid.pos.y))
	{
		meidFlag = false;
		meidCnt++;
	}

	// �����̓����蔻��
	if ((player.pos.x < mamono.pos.x + ENEMY_SIZE_X) &&
		(player.pos.x + PLAYER_SIZE_X > mamono.pos.x) &&
		(player.pos.y < mamono.pos.y + ENEMY_SIZE_Y) &&
		(player.pos.y + PLAYER_SIZE_Y > mamono.pos.y))
	{
		mamonoFlag = false;
		mamonoCnt++;
	}

	// ����2�̓����蔻��
	if ((player.pos.x < mamono2.pos.x + ENEMY_SIZE_X) &&
		(player.pos.x + PLAYER_SIZE_X > mamono2.pos.x) &&
		(player.pos.y < mamono2.pos.y + ENEMY_SIZE_Y) &&
		(player.pos.y + PLAYER_SIZE_Y > mamono2.pos.y))
	{
		mamono2Flag = false;
		mamono2Cnt++;
	}

	// �l�`�̓����蔻��
	if ((player.pos.x < ninngyou.pos.x + ENEMY_SIZE_X) &&
		(player.pos.x + PLAYER_SIZE_X > ninngyou.pos.x) &&
		(player.pos.y < ninngyou.pos.y + ENEMY_SIZE_Y) &&
		(player.pos.y + PLAYER_SIZE_Y > ninngyou.pos.y))
	{
		ninngyouFlag = false;
		ninngyouCnt++;
	}

	// �l�`2�̓����蔻��
	if ((player.pos.x < ninngyou2.pos.x + ENEMY_SIZE_X) &&
		(player.pos.x + PLAYER_SIZE_X > ninngyou2.pos.x) &&
		(player.pos.y < ninngyou2.pos.y + ENEMY_SIZE_Y) &&
		(player.pos.y + PLAYER_SIZE_Y > ninngyou2.pos.y))
	{
		ninngyou2Flag = false;
		ninngyou2Cnt++;
	}
}
