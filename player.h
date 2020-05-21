//#pragma once
//#pragma once

// �萔�錾
#define PLAYER_MAX 4				// �v���C���[��

#define PLAYER_SIZE_X 32			// �v���C���[�̉��T�C�Y
#define PLAYER_SIZE_Y 32			// �v���C���[�̏c�T�C�Y

#define ANIM_IMAGE_MAX 4


struct Pos
{
	int x;			// X���W
	int y;			// Y���W
};

// �v���C���[�p�̍\����
struct Player
{
	Pos pos;					// ���W
};


// �֐��̃v���g�^�C�v�錾
void playerInit(void);
void playerMove(void);
void playerDraw(void);

// extern�錾
extern int playerImage[CHAR_ID_MAX][ANIM_IMAGE_MAX];
extern int playerAnimCnt;
extern int kenImage;
extern int tueImage;
