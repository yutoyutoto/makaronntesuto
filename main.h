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

// キャラの種別
enum CHAR_ID
{
	CHAR_ID_MURABITO,
	CHAR_ID_HIME,
	CHAR_ID_MAX
};

// 定数宣言
#define SCREEN_SIZE_X 800			// 画面の横サイズ
#define SCREEN_SIZE_Y 600			// 画面の縦サイズ
#define PLAYER_MAX 3				// プレイヤー数

#define PLAYER_SIZE_X 32			// プレイヤーの横サイズ
#define PLAYER_SIZE_Y 32			// プレイヤーの縦サイズ

#define ANIM_IMAGE_MAX 4			// アニメーション数
#define ANIM_SPEED 30				// アニメーション速度

// ベクトル用の構造体
struct Pos
{
	int x;			// X座標
	int y;			// Y座標
};

struct XY
{
	int x;
	int y;
};

// プレイヤー用の構造体
struct Player
{
	Pos pos;					// 座標
};

// プロトタイプ宣言
void SisInit(void);
void GetKeyState(void);

// extern宣言
extern SCN_ID scnID;
extern bool rtnFlag;
extern bool spacekeyFlag;
extern bool spacekeyFlagOld;
extern int flamCnt;

