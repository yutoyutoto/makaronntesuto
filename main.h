//
// TestProject
//   by ��i�D�l
//
//#pragma once

// �萔�錾
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600
#ifdef _DEBUG
#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %d�s��\0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "�A�T�[�g�\��", MB_OK);\
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

// enum��`
enum SCN_ID
{
	SCN_ID_TITLE,			// �^�C�g��
	SCN_ID_GAME,			// �Q�[���V�[��
	SCN_ID_GAMEOVER,		// �Q�[���I�|�o�[
	SCN_ID_MAX
};

// �L�����̎��
enum CHAR_ID
{
	CHAR_ID_MURABITO,
	CHAR_ID_HIME,
	CHAR_ID_MAX
};


// �G
enum ENEMY {
	ENEMY_ID_MAOU,
	ENEMY_ID_MEIDO,
	ENEMY_ID_NINGYOU,
	ENEMY_ID_MAMONO,
	ENEMY_MAX
}; struct CHARACTER {
	XY pos;			//�G�̈ʒu�i���S�j
	XY size;		//�G�摜�̃T�C�Y
	XY sizeOffset;		//�G��������̍���ʒu
	XY hitPosS;		//�����蔻��p�̍���
	XY hitPosE;		//�����蔻��p�̉E��
	XY_F velocity;	// �G�̑��x

	int life;		//�G�̗̑�
	int lifeMax;		//�G�̗͍̑ő�
	int animCnt;		//�G�̃A�j���[�V�����p�J�E���^
	ENEMY type;			// ���炩�̓W�J

	bool visible;		// �\�����
	bool shotFlag;		//�G�̏�ԁi�e�����Ă��邩�H�j
	bool damageFlag;	//�G�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	int imgLockCnt;		//�G�̃C���[�W�Œ�p�J�E���^
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