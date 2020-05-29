//
// TestProject
//   by ��i�D�l
//
//#pragma once
// �f�o�b�N���b�Z�[�W�p�萔
#ifdef _DEBUG
#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %d�s��\0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "�A�T�[�g�\��", MB_OK);\
	}
#else
#define AST()
#endif


// enum��`
enum SCN_ID
{
	SCN_ID_TITLE,			// �^�C�g��
	SCN_ID_CHARSEL,			// �Z���N�g�V�[��
	SCN_ID_GAME,			// �Q�[���V�[��
	SCN_ID_GAMEOVER,		// �Q�[���I�|�o�[
	SCN_ID_MAX
};

// �ړ��p
struct XY
{
	int x;
	int y;
};

// �x�N�g���p�̍\����
struct Pos
{
	int x;			// X���W
	int y;			// Y���W
};


struct Player
{
	Pos pos;					// ���W
};

// �G�l�~�[�p�̍\����
struct Enemy
{
	Pos pos;					// ���W
};

//struct XY_F
//{
//	float x;
//	float y;
//};

enum DIR {
	DIR_UP,					// ��ړ�
	DIR_RIGHT,				// �E�ړ�
	DIR_MAX
};


// �L�����̎��
enum CHAR_ID
{
	CHAR_ID_MURABITO,
	CHAR_ID_HIME,
	CHAR_ID_MAX
}; 
struct CHARACTER {
	DIR moveDir;		//�����Ă������
	XY pos;			//�L�����N�^�̈ʒu�i���S�j
	XY size;		//�L�����N�^�摜�̃T�C�Y
	XY sizeOffset;		//�L�����N�^��������̍���ʒu
	XY hitPosS;		//�����蔻��p�̍���
	XY hitPosE;		//�����蔻��p�̉E��
	//XY_F velocity;	// �L�����N�^�̑��x

	int moveSpeed;		//�L�����N�^�̈ړ���
	int life;		//�L�����N�^�̗̑�
	int lifeMax;		//�L�����N�^�̗͍̑ő�
	int animCnt;		//�L�����N�^�̃A�j���[�V�����p�J�E���^

	//bool visible;		// �\�����
	bool runFlag;		//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	bool jumpFlag;		//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	bool shotFlag;		//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	bool damageFlag;	//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	int imgLockCnt;		//�L�����N�^�̃C���[�W�Œ�p�J�E���^
};

// �萔�錾
#define SCREEN_SIZE_X 800			// ��ʂ̉��T�C�Y
#define SCREEN_SIZE_Y 600			// ��ʂ̏c�T�C�Y
#define PLAYER_MAX 3				// �v���C���[��

#define PLAYER_SIZE_X 32			// �v���C���[�̉��T�C�Y
#define PLAYER_SIZE_Y 32			// �v���C���[�̏c�T�C�Y


#define ENEMY_SIZE_X 60				// �G�l�~�[�̉��T�C�Y
#define ENEMY_SIZE_Y 60				// �G�l�~�[�̏c�T�C�Y

#define ANIM_IMAGE_MAX 4			// �A�j���[�V������
#define ANIM_SPEED 30				// �A�j���[�V�������x




// �v���g�^�C�v�錾
void SisInit(void);
void GetKeyState(void);

// extern�錾
extern SCN_ID scnID;
extern bool rtnFlag;
extern bool spacekeyFlag;
extern bool spacekeyFlagOld;
extern int flamCnt;

