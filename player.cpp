#include "Dxlib.h"
#include "main.h"
#include "player.h"

// �ϐ��̒�`
Player player;
Pos playerSpeed;

int Gravity;
int jumpCnt;


// �v���C���[�̏�����
void playerInit(void)
{
	playerSpeed.x = 0;
	playerSpeed.y = 5;
	Gravity = 3;
	jumpCnt = 0;
}

// �v���C���[�̕`��
void playerDraw(void)
{

}

// �v���C���[�̓���
void playerMove(void)
{
	/*if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		player.pos.x += 5;
	}*/

	if (CheckHitKey(KEY_INPUT_UP))
	{
		player.pos.y = player.pos.y - playerSpeed.y + Gravity * jumpCnt;
		jumpCnt++;
		if (playerSpeed.y <= 0)
		{
			playerSpeed.y = 0;
			jumpCnt = 0;
		}
	}
}