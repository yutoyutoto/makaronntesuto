//#pragma once

#define MAP_X 600			// �c�����̐�
#define MAP_Y 40			// �������̐�
#define CHIP_SIZE_X 32		// �`�b�v1�̃T�C�YX
#define CHIP_SIZE_Y 32		// �`�b�v1�̃T�C�YY


void StageGameDraw(void);
void StageSystemInit(void);
void SetMapData();

extern XY mapPos;