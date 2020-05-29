//
// TestProject
//   by 若永優斗
//
//#pragma once
// デバックメッセージ用定数
#ifdef _DEBUG
#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %d行目\0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "アサート表示", MB_OK);\
	}
#else
#define AST()
#endif


// enum定義
enum SCN_ID
{
	SCN_ID_TITLE,			// タイトル
	SCN_ID_CHARSEL,			// セレクトシーン
	SCN_ID_GAME,			// ゲームシーン
	SCN_ID_GAMEOVER,		// ゲームオ－バー
	SCN_ID_MAX
};

// 移動用
struct XY
{
	int x;
	int y;
};

// ベクトル用の構造体
struct Pos
{
	int x;			// X座標
	int y;			// Y座標
};


struct Player
{
	Pos pos;					// 座標
};

// エネミー用の構造体
struct Enemy
{
	Pos pos;					// 座標
};

//struct XY_F
//{
//	float x;
//	float y;
//};

enum DIR {
	DIR_UP,					// 上移動
	DIR_RIGHT,				// 右移動
	DIR_MAX
};


// キャラの種別
enum CHAR_ID
{
	CHAR_ID_MURABITO,
	CHAR_ID_HIME,
	CHAR_ID_MAX
}; 
struct CHARACTER {
	DIR moveDir;		//向いている方向
	XY pos;			//キャラクタの位置（中心）
	XY size;		//キャラクタ画像のサイズ
	XY sizeOffset;		//キャラクタ中央からの左上位置
	XY hitPosS;		//当たり判定用の左上
	XY hitPosE;		//当たり判定用の右下
	//XY_F velocity;	// キャラクタの速度

	int moveSpeed;		//キャラクタの移動量
	int life;		//キャラクタの体力
	int lifeMax;		//キャラクタの体力最大
	int animCnt;		//キャラクタのアニメーション用カウンタ

	//bool visible;		// 表示状態
	bool runFlag;		//キャラクタの状態（走っているか？）
	bool jumpFlag;		//キャラクタの状態（ジャンプしているか？）
	bool shotFlag;		//キャラクタの状態（弾撃っているか？）
	bool damageFlag;	//キャラクタの状態（ダメージ受けているか？）
	int imgLockCnt;		//キャラクタのイメージ固定用カウンタ
};

// 定数宣言
#define SCREEN_SIZE_X 800			// 画面の横サイズ
#define SCREEN_SIZE_Y 600			// 画面の縦サイズ
#define PLAYER_MAX 3				// プレイヤー数

#define PLAYER_SIZE_X 32			// プレイヤーの横サイズ
#define PLAYER_SIZE_Y 32			// プレイヤーの縦サイズ


#define ENEMY_SIZE_X 60				// エネミーの横サイズ
#define ENEMY_SIZE_Y 60				// エネミーの縦サイズ

#define ANIM_IMAGE_MAX 4			// アニメーション数
#define ANIM_SPEED 30				// アニメーション速度




// プロトタイプ宣言
void SisInit(void);
void GetKeyState(void);

// extern宣言
extern SCN_ID scnID;
extern bool rtnFlag;
extern bool spacekeyFlag;
extern bool spacekeyFlagOld;
extern int flamCnt;

