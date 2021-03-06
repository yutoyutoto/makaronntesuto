//#pragma once

#define MAP_X 600			// 縦方向の数
#define MAP_Y 40			// 横方向の数
#define CHIP_SIZE_X 32		// チップ1つのサイズX
#define CHIP_SIZE_Y 32		// チップ1つのサイズY


void StageGameDraw(void);
void StageSystemInit(void);
//void SetMapData(void);

bool IsPass(XY pos);		// 指定された座標が通過可能かを判断する
XY PosToIndex(XY pos);
XY IndexToPos(XY index);
extern XY mapPos;