//
//  animal.cpp
//  xiaochu
//
//  Created by apple on 15/3/10.
//
//

#include "smallStone.h"

smallStone* smallStone::createStone(int row, int col)
{
	smallStone *sprite = new (std::nothrow) smallStone();
	sprite->_row = row;
	sprite->_col = col;
	sprite->_imgIndex = rand() % TOTAL_SPRITE;
	SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteNormal[sprite->_imgIndex][0]);

	if (sprite && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void smallStone::doAnimate(stoneAnimateType type)
{

}
