#include "Dxlib.h"
#include "main.h"
#include "player.h"
#include "Stage.h"
// 変数の定義
Player player;
Pos playerSpeed;

int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
int playerAnimCnt;

int keyFlag;
int Gravity;
int jumpCnt;


// プレイヤーの初期化
void PlayerInit(void)
{
	bool rtnFlag = true;
	for (int j = 0; j < ANIM_IMAGE_MAX; j++)
	{
		if (LoadDivGraph("image/murabito.bmp", ANIM_IMAGE_MAX, ANIM_IMAGE_MAX, 1,
			PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[0][j]) == -1)
		{
			AST();
			rtnFlag = false;
		}
	}

	/*if (LoadDivGraph("Image/hime.dib.bmp", ANIM_IMAGE_MAX * DIR_MAX, ANIM_IMAGE_MAX, DIR_MAX,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[0][0]) == -1)
	{
		AST();
		rtnFlag = false;
	}*/
	player.pos.x = 0;
	player.pos.y = 560;
	keyFlag = 0;

	playerSpeed.x = 5;
	playerSpeed.y = 30;
	Gravity = 3;
	jumpCnt = 0;
}


// プレイヤーの動き
void PlayerMove(void)
{
	/*if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		player.pos.x += 5;
	}*/

	player.pos.x += 1;
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
	if (player.pos.x >= SCREEN_SIZE_X)
	{
		player.pos.x = 0;
	}
}

// プレイヤーの描画
void PlayerDraw(void)
{
	//ClsDrawScreen();		// 画面消去
	if (playerAnimCnt == 4)
	{
		playerAnimCnt = 0;
	}
	DrawGraph(player.pos.x, player.pos.y, playerImage[CHAR_ID_MURABITO][playerAnimCnt], true);
	playerAnimCnt++;
	PlayerMove();
	//ScreenFlip();			// バックバッファをフロントバッファに入れ替える
}
