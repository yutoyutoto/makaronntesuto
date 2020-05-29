#include "time.h"
#include <math.h>
#include "Dxlib.h"
#include "main.h"
#include "enemy.h"

// �ϐ��̒�`
Enemy enemy;
Enemy maou;
Enemy meid;
Enemy mamono;
Enemy mamono2;
Enemy ninngyou;
Enemy ninngyou2;

bool enemyFlag;
bool maouFlag;
bool meidFlag;
bool mamonoFlag;
bool mamono2Flag;
bool ninngyouFlag;
bool ninngyou2Flag;

int enemyCnt;
int maouCnt;
int meidCnt;
int mamonoCnt;
int mamono2Cnt;
int ninngyouCnt;
int ninngyou2Cnt;


// �C���[�W�p
int maouImage;
int meidImage;
int meid2Image;
int mamonoImage;
int mamono2Image;
int ninngyouImage;
int ninngyou2Image;

// �G�̏�����
void enemyInit(void)
{
	bool rtnFlag = true;

	srand(time(NULL));

	// ����
	maouImage = LoadGraph("Image/maou.png");
	if (maouImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	// ���C�h
	meidImage = LoadGraph("Image/meid.png");
	if (meidImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	meid2Image = LoadGraph("Image/meid2.png");
	if (meid2Image == -1)
	{
		AST();
		rtnFlag = false;
	}

	// ����
	mamonoImage = LoadGraph("Image/mamono.png");
	if (mamonoImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	mamono2Image = LoadGraph("Image/mamono2.png");
	if (mamono2Image == -1)
	{
		AST();
		rtnFlag = false;
	}

	// �l�`
	ninngyouImage = LoadGraph("Image/ninngyou.png");
	if (ninngyouImage == -1)
	{
		AST();
		rtnFlag = false;
	}

	ninngyou2Image = LoadGraph("Image/ninngyou2.bmp");
	if (ninngyou2Image == -1)
	{
		AST();
		rtnFlag = false;
	}

	enemyCnt = 0;

	// �����̏�����
	maou.pos.x = SCREEN_SIZE_X + ENEMY_SIZE_X;
	maou.pos.y = rand() % 540;
	maouFlag = true;
	maouCnt = 0;

	// ���C�h�̏�����
	meid.pos.x = rand() % 600;
	meid.pos.y = rand() % 540;
	meidFlag = true;
	meidCnt = 0;

	// �����̏�����
	mamono.pos.x = rand() % 600;
	mamono.pos.y = rand() % 540;
	mamonoFlag = true;
	mamonoCnt = 0;

	// ����2�̏�����
	mamono2.pos.x = rand() % 600;
	mamono2.pos.y = rand() % 540;
	mamono2Flag = true;
	mamono2Cnt = 0;

	// �l�`�̏�����
	ninngyou.pos.x = rand() % 600;
	ninngyou.pos.y = rand() % 540;
	ninngyouFlag = true;
	ninngyouCnt = 0;

	// �l�`2�̏�����
	ninngyou2.pos.x = rand() % 600;
	ninngyou2.pos.y = rand() % 540;
	ninngyou2Flag = true;
	ninngyou2Cnt = 0;
	//enemyFlag = true;
}

// �G�̓���
void enemyMove(void)
{
	// -----�G�l�~�[����ʊO�ɍs���������-----
	// ����
	if (maou.pos.x <= 0 - ENEMY_SIZE_X)
	{
		maouFlag = false;
		maouCnt++;
	}

	// ���C�h
	if (meid.pos.x <= 0 - ENEMY_SIZE_X)
	{
		meidFlag = false;
		meidCnt++;
	}

	// ����
	if (mamono.pos.x <= 0 - ENEMY_SIZE_X)
	{
		mamonoFlag = false;
		mamonoCnt++;
	}

	// ����2
	if (mamono2.pos.x <= 0 - ENEMY_SIZE_X)
	{
		mamono2Flag = false;
		mamono2Cnt++;
	}

	// �l�`
	if (ninngyou.pos.x <= 0 - ENEMY_SIZE_X)
	{
		ninngyouFlag = false;
		ninngyouCnt++;
	}

	// �l�`2
	if (ninngyou2.pos.x <= 0 - ENEMY_SIZE_X)
	{
		ninngyou2Flag = false;
		ninngyou2Cnt++;
	}

	// -----�G�l�~�[�̍ĕ`��-----
	// ����
	if ((maouFlag == false) && (maouCnt > 100))
	{
		maou.pos.x = SCREEN_SIZE_X + ENEMY_SIZE_X;
		maou.pos.y = rand() % 540;
		maouFlag = true;
		maouCnt = 0;
	}

	// ���C�h
	if ((meidFlag == false) && (meidCnt > 100))
	{
		meid.pos.x = SCREEN_SIZE_X + ENEMY_SIZE_X;
		meid.pos.y = rand() % 540;
		meidFlag = true;
		meidCnt = 0;
	}

	// ����
	if ((mamonoFlag == false) && (mamonoCnt > 100))
	{
		mamono.pos.x = SCREEN_SIZE_X + ENEMY_SIZE_X;
		mamono.pos.y = rand() % 540;
		mamonoFlag = true;
		mamonoCnt = 0;
	}

	// ����2
	if ((mamono2Flag == false) && (mamono2Cnt > 100))
	{
		mamono2.pos.x = SCREEN_SIZE_X + ENEMY_SIZE_X;
		mamono2.pos.y = rand() % 540;
		mamono2Flag = true;
		mamono2Cnt = 0;
	}

	// �l�`
	if ((ninngyouFlag == false) && (ninngyouCnt > 100))
	{
		ninngyou.pos.x = SCREEN_SIZE_X + ENEMY_SIZE_X;
		ninngyou.pos.y = rand() % 540;
		ninngyouFlag = true;
		ninngyouCnt = 0;
	}

	// �l�`2
	if ((ninngyou2Flag == false) && (ninngyou2Cnt > 100))
	{
		ninngyou2.pos.x = SCREEN_SIZE_X + ENEMY_SIZE_X;
		ninngyou2.pos.y = rand() % 540;
		ninngyou2Flag = true;
		ninngyou2Cnt = 0;
	}
}

// �G�̕`��
void enemyDraw(void)
{
	// �����̕`��
	if (maouFlag)
	{
		DrawGraph(maou.pos.x, maou.pos.y, maouImage, true);
		maou.pos.x -= 3;
	}

	// ���C�h�̕`��
	if (meidFlag)
	{
		DrawGraph(meid.pos.x, meid.pos.y, meidImage, true);
		meid.pos.x -= 3;
	}

	// �����̕`��
	if (mamonoFlag)
	{
		DrawGraph(mamono.pos.x, mamono.pos.y, mamonoImage, true);
		mamono.pos.x -= 3;
	}

	// ����2�̕`��
	if (mamono2Flag)
	{
		DrawGraph(mamono2.pos.x, mamono2.pos.y, mamono2Image, true);
		mamono2.pos.x -= 3;
	}

	// �l�`�̕`��
	if (ninngyouFlag)
	{
		DrawGraph(ninngyou.pos.x, ninngyou.pos.y, ninngyouImage, true);
		ninngyou.pos.x -= 3;
	}
	// �l�`2�̕`��
	if (ninngyou2Flag)
	{
		DrawGraph(ninngyou2.pos.x, ninngyou2.pos.y, ninngyou2Image, true);
		ninngyou2.pos.x -= 3;
	}
	enemyMove();
}