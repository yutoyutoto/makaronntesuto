#include "Dxlib.h"
#include "main.h"
#include "player.h"

// 変数の定義
Player player;
Pos playerSpeed;

int Gravity;
int jumpCnt;


// プレイヤーの初期化
void playerInit(void)
{
	playerSpeed.x = 0;
	playerSpeed.y = 5;
	Gravity = 3;
	jumpCnt = 0;
}

// プレイヤーの描画
void playerDraw(void)
{

}

// プレイヤーの動き
void playerMove(void)
{
	/*if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		player.pos.x += 5;
	}*/

	if (CheckHitKey(KEY_INPUT_UP))
	{
		player.pos.y = player.pos.y - playerSpeed.y + Gravity * jumpCnt;
		jumpCnt++;
		if (playerSpeed.y <= 0)
		{
			playerSpeed.y = 0;
			jumpCnt = 0;
		}
	}
}