#pragma once

// 関数のプロトタイプ宣言
void playerInit(void);
void playerMove(void);
void playerDraw(void);
void enemyObj(void);

// extern宣言
extern Player player;
extern int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
extern int playerAnimCnt;
extern int kenImage;
extern int jyuuImage;
extern int tueImage;

