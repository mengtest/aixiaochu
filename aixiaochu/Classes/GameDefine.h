#ifndef  _Inkmoo_Elimination_h_
#define  _Inkmoo_Elimination_h_

// 定义屏幕宽高，这与所做的图片有关
#define GAME_SCREEN_WIDTH 480
#define GAME_SCREEN_HEIGHT 800

// 定义每个精灵大小与边框大小
#define SPRITE_WIDTH 48
#define BOADER_WIDTH 2

// 游戏精灵行数和列数
#define ROWS 8
#define COLS 8

// 精灵种类总数
#define TOTAL_SPRITE 14
#define SPRITE_KIND_NUM 5

// 分数存储
#define userDefault CCUserDefault::sharedUserDefault()

// 音乐音效
#include "SimpleAudioEngine.h"
#define SOUND_KEY "sound_key"
#define MUSIC_KEY "music_key"

// 精灵的显示模式，Hor 横向消除一行，Ver纵向消除一列
enum DisplayMode{
    DISPLAY_MODE_NORMAL = 0,
    DISPLAY_MODE_HORIZONTAL,
    DISPLAY_MODE_VERTICAL,
};

// 普通的精灵
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