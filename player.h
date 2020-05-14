//#pragma once
//#pragma once

// 定数宣言
#define PLAYER_MAX 3				// プレイヤー数

// ベクトル用の構造体
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
void playerDraw(void);

