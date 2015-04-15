#ifndef  _Inkmoo_Elimination_h_
#define  _Inkmoo_Elimination_h_

// ������Ļ��ߣ�����������ͼƬ�й�
#define GAME_SCREEN_WIDTH 480
#define GAME_SCREEN_HEIGHT 800

// ����ÿ�������С��߿��С
#define SPRITE_WIDTH 48
#define BOADER_WIDTH 2

// ��Ϸ��������������
#define ROWS 8
#define COLS 8

// ������������
#define TOTAL_SPRITE 14
#define SPRITE_KIND_NUM 5

// �����洢
#define userDefault CCUserDefault::sharedUserDefault()

// ������Ч
#include "SimpleAudioEngine.h"
#define SOUND_KEY "sound_key"
#define MUSIC_KEY "music_key"

// �������ʾģʽ��Hor ��������һ�У�Ver��������һ��
enum DisplayMode{
    DISPLAY_MODE_NORMAL = 0,
    DISPLAY_MODE_HORIZONTAL,
    DISPLAY_MODE_VERTICAL,
};

// ��ͨ�ľ���
static const char *spriteNormal[TOTAL_SPRITE][SPRITE_KIND_NUM] =
{
	"001_a.png", "001_b.png", "001_c.png", "001_d.png", "001_e.png",
	"002_a.png", "002_b.png", "002_c.png", "002_d.png", "002_e.png",
	"003_a.png", "003_b.png", "003_c.png", "003_d.png", "003_e.png",
	"004_a.png", "004_b.png", "004_c.png", "004_d.png", "004_e.png",
	"005_a.png", "005_b.png", "005_c.png", "005_d.png", "005_e.png",
	"006_a.png", "006_b.png", "006_c.png", "006_d.png", "006_e.png",
	"007_a.png", "007_b.png", "007_c.png", "007_d.png", "007_e.png",
	"008_a.png", "008_b.png", "008_c.png", "008_d.png", "008_e.png",
	"009_a.png", "009_b.png", "009_c.png", "009_d.png", "009_e.png",
	"010_a.png", "010_b.png", "010_c.png", "010_d.png", "010_e.png",
	"011_a.png", "011_b.png", "011_c.png", "011_d.png", "011_e.png",
	"012_a.png", "012_b.png", "012_c.png", "012_d.png", "012_e.png",
	"013_a.png", "013_b.png", "013_c.png", "013_d.png", "013_e.png",
	"014_a.png", "014_b.png", "014_c.png", "014_d.png", "014_e.png",
    

};

#endif