//#pragma once
//#pragma once

// �萔�錾
#define PLAYER_MAX 3				// �v���C���[��

// �x�N�g���p�̍\����
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
void playerDraw(void);

