#include <math.h>
#include "Dxlib.h"
#include "main.h"
#include "SelectScene.h"
#include "player.h"
#include "Stage.h"

// 変数の定義
CHARACTER player;
Pos playerSpeed;

// イメージ用
int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
int kenImage;
int jyuuImage;
int tueImage;
int gumiImage;
int eriImage;

int playerAnimCnt;		// アニメーションの速さ
int keyFlag;
int Gravity;
int jumpCnt;
int jump2Cnt;


// プレイヤーの初期化
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
	// プレイヤーの初期化
	player.pos.x = 0;
	player.pos.y = 500;
	keyFlag = 0;
	player.hitPosE = { 0,0 };
	player.hitPosS = { 0,0 };
	playerSpeed.x = 2;
	playerSpeed.y = 30;
	Gravity = 2;
	jumpCnt = 0;
	jump2Cnt = 0;
}


// プレイヤーの動き
int playerMove(int center)
{
	// プレイヤーの座標コピー
	XY PlayerPosCopy = player.pos;
	// プレイヤーの当たり判定
	XY playerHitPos;
	XY PlayerHitPosLeft;
	XY PlayerHitPosRight;
	XY PlayerHitPosBottom;
	XY PlayerHitPosTop;
	XY tempPos;

	playerHitPos = PlayerPosCopy;
	// 右移動
	player.pos.x += 1;
	// 1回目のジャンプの処理
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

	// 2回目のジャンプ処理
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
	// 繰り返し
	if (player.pos.x >= SCREEN_SIZE_X)
	{
		player.pos.x = 0;
	}
	// 剣の回転
	
		// プレイヤーとマップの当たり判定
		PlayerHitPosBottom = playerHitPos;
		PlayerHitPosTop = playerHitPos;
		PlayerHitPosBottom.y += player.hitPosE.y - 1;
		PlayerHitPosTop.y -= player.hitPosS.y;
		PlayerHitPosLeft = playerHitPos;
		PlayerHitPosLeft.y -= player.hitPosS.y;
		PlayerHitPosRight = playerHitPos;
		PlayerHitPosRight.x += player.hitPosE.x;

			if (!IsPass(playerHitPos) || !IsPass(PlayerHitPosRight) || !IsPass(PlayerHitPosLeft))
			{
				// 頭上の判定
				tempPos = PosToIndex(playerHitPos);
				tempPos.y++;
				tempPos = IndexToPos(tempPos);
				PlayerPosCopy.y = tempPos.y + player.hitPosS.y;
			}
			// プレイヤーの足元の座標
			playerHitPos.y = PlayerPosCopy.y + player.hitPosE.y;
			PlayerHitPosRight = playerHitPos;
			PlayerHitPosRight.x += player.hitPosE.x;
			PlayerHitPosLeft = playerHitPos;
			PlayerHitPosLeft.x -= player.hitPosS.x;
			if (IsPass(playerHitPos) && IsPass(PlayerHitPosRight) && IsPass(PlayerHitPosLeft))
			{
				// ジャンプを続ける場合は座標を更新
				player.pos.y = PlayerPosCopy.y;
			}
			else
			{
				// ジャンプを終了する場合は移動をキャンセル　&　ジャンプの停止
				//player.jumpFlag = false;
				// 床にきれいに乗る
				player.pos.y = PosToIndex(PlayerPosCopy).y * CHIP_SIZE_Y;
				//playerTime = 0.0f;
			}
			/*if (!player.jumpFlag)
			{
				if (CheckHitKey(KEY_INPUT_W) || CheckHitKey(KEY_INPUT_A))
				{
					player.jumpFlag = true;
				}
			}*/
	return player.pos.y;
}

// プレイヤーの描画
void playerDraw(void)
{
	//ClsDrawScreen();		// 画面消去
	/*if (playerAnimCnt == 4)
	{
		playerAnimCnt = 0;
	}*/
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
		DrawGraph(player.pos.x, player.pos.y - 5, tueImage, true);
	}
	DrawGraph(0, 0, eriImage, true);
	//playerMove();
	//ScreenFlip();			// バックバッファをフロントバッファに入れ替える
}
