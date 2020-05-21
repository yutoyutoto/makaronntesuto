#include "DxLib.h"
#include "main.h"
#include "Stage.h"
#include "player.h"
int mapImage[40];
int map[MAP_Y][MAP_X];

// 地図の描画
int stage[MAP_Y][MAP_X] =
{
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,10,10,10,10,10,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,  10,10,10,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,10,10,10,10,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,10,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,10,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,10,10,10,10,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,10,10,10,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,10,10,10,10,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,10,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,10,10,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,10,10,10,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,10,10,10,10,5,5,5,5,5,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,10,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,10,  10,10,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,10,10,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,10,5,  5,5,5,5,5,5,5,5,5,5,	5,5,5,10,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,10,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,10,10,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,10,10,10,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,10,10,10,10,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,  10,10,5,5,5,10,5,5,5,5,  5,5,5,10,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,10,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,10,10,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,10,10,5,  5,5,5,5,5,5,5,10,10,5,	5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,10,10,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,  10,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,10,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,10,5,5,5,5,5,5,5,5,  5,5,10,10,10,10,10,5,5,5,  5,5,5,10,10,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,10,10,10,5,  5,5,5,5,5,5,5,10,10,5,	5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,10,10,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,10,10,10,10,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,10,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,10,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,10,5,5,5,5,5,5,5,5,  10,10,5,5,5,5,5,5,5,5,  5,5,5,10,10,5,5,5,5,5,  5,5,5,5,5,5,5,10,10,10,  10,10,10,10,10,10,10,10,10,5,  5,5,5,5,5,5,5,10,10,5,	5,5,5,5,5,5,5,5,5,10,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,10,  10,10,10,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1},
	
};
XY mapSize;
XY mapPos;
void StageSystemInit(void)
{
	// マップの画像読み込み
	LoadDivGraph("image/map.bmp", 40, 10, 4, CHIP_SIZE_X, CHIP_SIZE_Y, mapImage);
	for (int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{
			map[y][x] = stage[y][x];
		}
	}
	mapSize.x = MAP_X;
	mapSize.y = MAP_Y;
}
// ステージの描画
void StageGameDraw(void)
{
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			DrawGraph(x * CHIP_SIZE_X + (-mapPos.x), y * CHIP_SIZE_Y + (-mapPos.y), mapImage[map[y][x]], true);
		}
	}
}
// プレイヤーとマップの移動
XY PosToIndex(XY pos)
{
	XY chipPos;
	chipPos.x = pos.x / CHIP_SIZE_X;
	chipPos.y = pos.y / CHIP_SIZE_Y;
	return chipPos;
}

bool IsPas(XY pos)
{
	XY index;
	index = PosToIndex(pos);
	switch (map[index.y][index.x])
	{
	case 10:
			return false;
			break;
	default:
		break;
	}
	return true;
}
//void SetMapData()
//{
//	
//}