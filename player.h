#pragma once

// �֐��̃v���g�^�C�v�錾
void playerInit(void);
void playerMove(void);
void playerDraw(void);
void enemyObj(void);

// extern�錾
extern Player player;
extern int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
extern int playerAnimCnt;
extern int kenImage;
extern int jyuuImage;
extern int tueImage;

