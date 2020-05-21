//#pragma once
//#pragma once

// 定数宣言
#define PLAYER_MAX 4				// プレイヤー数

#define PLAYER_SIZE_X 32			// プレイヤーの横サイズ
#define PLAYER_SIZE_Y 32			// プレイヤーの縦サイズ

#define ANIM_IMAGE_MAX 4


struct Pos
{
	int x;			// X座標
	int y;			// Y座標
};

// プレイヤー用の構造体
struct Player
{
	Pos pos;					// 座標
};


// 関数のプロトタイプ宣言
void playerInit(void);
void playerMove(void);
void playerDraw(void);

// extern宣言
extern int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
extern int playerAnimCnt;
extern int kenImage;
extern int tueImage;
