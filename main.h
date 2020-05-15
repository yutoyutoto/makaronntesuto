//
// TestProject
//   by ��i�D�l
//
//#pragma once

// �萔�錾
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

struct XY
{
	int x;
	int y;
};

// �v���g�^�C�v�錾
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