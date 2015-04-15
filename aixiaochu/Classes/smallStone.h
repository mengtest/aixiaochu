//
//  animal.h
//  xiaochu
//
//  Created by apple on 15/3/10.
//
//

#ifndef __xiaochu__animal__
#define __xiaochu__animal__

#include "cocos2d.h"
#include "GameDefine.h"

USING_NS_CC;

class smallStone:public Sprite
{
public:
	enum class stoneAnimateType
	{
		ani_shake,//»Î¶¯
		ani_cute,//ÂôÃÈ
		ani_whiteEyw//°×ÑÛ
	};
public:
	static smallStone * createStone(int row, int col);
    
	void doAnimate(stoneAnimateType type);
    
private:
    CC_SYNTHESIZE(int, _row, Row);//ÐÐ
    CC_SYNTHESIZE(int, _col, Col);//ÁÐ
	CC_SYNTHESIZE(int, _imgIndex, ImgIndex);
	CC_SYNTHESIZE(bool, _isNeedRemove, IsNeedRemove);
	CC_SYNTHESIZE(bool, _ignoreCheck, IgnoreCheck);
	CC_SYNTHESIZE_READONLY(DisplayMode, _displayMode, DisplayMode);
};

#endif /* defined(__xiaochu__animal__) */


