//
// TestProject
//   by 若永優斗
//
//#pragma once

// 定数宣言
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600
#ifdef _DEBUG
#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %d行目\0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "アサート表示", MB_OK);\
	}
#else
#define AST()
#endif
struct XY
{
	int x;
	int y;
};

struct XY_F
{
	float x;
	float y;
};

// enum定義
enum SCN_ID
{
	SCN_ID_TITLE,			// タイトル
	SCN_ID_GAME,			// ゲームシーン
	SCN_ID_GAMEOVER,		// ゲームオ－バー
	SCN_ID_MAX
};

// キャラの種別
enum CHAR_ID
{
	CHAR_ID_MURABITO,
	CHAR_ID_HIME,
	CHAR_ID_MAX
};


// 敵
enum ENEMY {
	ENEMY_ID_MAOU,
	ENEMY_ID_MEIDO,
	ENEMY_ID_NINGYOU,
	ENEMY_ID_MAMONO,
	ENEMY_MAX
}; struct CHARACTER {
	XY pos;			//敵の位置（中心）
	XY size;		//敵画像のサイズ
	XY sizeOffset;		//敵中央からの左上位置
	XY hitPosS;		//当たり判定用の左上
	XY hitPosE;		//当たり判定用の右下
	XY_F velocity;	// 敵の速度

	int life;		//敵の体力
	int lifeMax;		//敵の体力最大
	int animCnt;		//敵のアニメーション用カウンタ
	ENEMY type;			// 何らかの展開

	bool visible;		// 表示状態
	bool shotFlag;		//敵の状態（弾撃っているか？）
	bool damageFlag;	//敵の状態（ダメージ受けているか？）
	int imgLockCnt;		//敵のイメージ固定用カウンタ
};


// プロトタイプ宣言
void GameMain(void);
void GameDraw(void);

bool SystemInit(void);

void InitScene(void);

void TitleScene(void);
void TitleDraw(void);
void RizartScene(void);
void RizartDraw(void);

void GameOverScene(void);
void GameOverDraw(void);