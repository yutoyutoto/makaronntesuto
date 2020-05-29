#pragma once

// 関数のプロトタイプ宣言
void playerInit(void);
int playerMove(int center);
void playerDraw(void);

// extern宣言
extern int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
extern int playerAnimCnt;
extern int kenImage;
extern int jyuuImage;
extern int tueImage;


