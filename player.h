//#pragma once
//#pragma once

// �萔�錾
#define PLAYER_MAX 3				// �v���C���[��
#define PLAYER_MAX 3				// �v���C���[��

#define PLAYER_SIZE_X 32			// �v���C���[�̉��T�C�Y
#define PLAYER_SIZE_Y 32			// �v���C���[�̏c�T�C�Y

#define ANIM_IMAGE_MAX 3


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
void PlayerDraw(void);
void PlayerInit(void);
void PlayerMove(void);

