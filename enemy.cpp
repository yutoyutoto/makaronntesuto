#include "DxLib.h"
#include "main.h"
#include "enemy.h"

 
ENEMY enemy;

int MaouImage;
int MeidImage[2];
int MamonoImage;
int NingyouImage;

// �G�̏�����
void EnemyInt(void)
{
	MaouImage = LoadGraph("image/maou.png");
	LoadGraph("image/mamono.png", MamonoImage);
	LoadGraph("image/ningyou.png", NingyouImage);
	MeidImage[STOP] = LoadGraph("image/maid2.png");
	MeidImage[SHOT] = LoadGraph("image/maid.png");
}
// �G�̃R���g���[��
void EnenmyCon(void)
{

}
// �G�̕`��
void EnemyDraw(void)
{
	DrawTurnGraph(40, 40, MaouImage, true);
}

