#include <math.h>
#include "Dxlib.h"
#include "main.h"
#include "enemy.h"

// •Ï”‚Ì’è‹`
// ƒCƒ[ƒW—p
int maouImage;

// “G‚Ì‰Šú‰»
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

// “G‚Ì“®‚«
void enemyMove(void)
{

}

// “G‚Ì•`‰æ
void enemyDraw(void)
{
	DrawGraph(0, 0, maouImage, true);
}