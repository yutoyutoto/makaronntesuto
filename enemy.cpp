#include <math.h>
#include "Dxlib.h"
#include "main.h"
#include "enemy.h"

// �ϐ��̒�`
// �C���[�W�p
int maouImage;

// �G�̏�����
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

// �G�̓���
void enemyMove(void)
{

}

// �G�̕`��
void enemyDraw(void)
{
	DrawGraph(0, 0, maouImage, true);
}