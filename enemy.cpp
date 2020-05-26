#include <math.h>
#include "Dxlib.h"
#include "main.h"
#include "enemy.h"

// 変数の定義
// イメージ用
int maouImage;

// 敵の初期化
void enemyInit(void)
{
	bool rtnFlag = true;

	maouImage = LoadGraph("Image/maou.png");
	if (maouImage == -1)
	{
		AST();
		rtnFlag = false;
	}
}

// 敵の動き
void enemyMove(void)
{

}

// 敵の描画
void enemyDraw(void)
{
	DrawGraph(0, 0, maouImage, true);
}