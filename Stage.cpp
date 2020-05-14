#include "DxLib.h"
#include "main.h"
#include "Stage.h"

int mapImage[40];
int map[MAP_Y][MAP_X];

// ínê}ÇÃï`âÊ
int satage[MAP_Y][MAP_X] =
{
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1}
};

void StageSystemInit(void)
{
	//
	LoadDivGraph("image/map.bmp", 40, 10, 4, CHIP_SIZE_X, CHIP_SIZE_Y, mapImage);
}
void StageGameDraw(void)
{
	DrawGraph(CHIP_SIZE_X, CHIP_SIZE_Y, mapImage[1], true);
	
}

void SetMapData()
{

}