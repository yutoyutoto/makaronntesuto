#include "Dxlib.h"
#include "main.h"
#include "GameOverScene.h"
#include "TitleScene.h"


// �Q�[���I�[�o�[�V�[���̏�����
void GameOverInit(void)
{

}

// �Q�[���I�[�o�[�V�[��
void GameOverScene(void)
{
	TitleInit();
}

// �Q�[���I�[�o�[�V�[���̕`��
void GameOverDraw(void)
{
	ClsDrawScreen();
	ScreenFlip();
}