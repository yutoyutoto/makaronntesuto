#include "DxLib.h"
#include "main.h"
#include "Stage.h"

int mapImage[40];
int map[MAP_Y][MAP_X];

// �n�}�̕`��
int stage[MAP_Y][MAP_X] =
{
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5,5,5},
	{1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1},
	
};
XY mapSize;
XY mapPos;
void StageSystemInit(void)
{
	// �}�b�v�̕`��
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

void SetMapData()
{
	
}