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
	switch (type)
	{
	case smallStone::stoneAnimateType::ani_shake:
		{
			const int shake_tag = 1111;
			if (this->getActionByTag(shake_tag))
			{
				break;
			}
			const int MAX_OFFSET = 20;
			int offset = MAX_OFFSET;
			float time = 0.08f;
			auto size = this->getContentSize();
			//size.width = 200;
			//size.height = 200;

			auto scaleX = (size.width + offset) / size.width;
			auto scaleY = (size.height - offset) / size.height;

			auto sq1 = Sequence::create(MoveBy::create(time, Point(0, 0- offset)),
				ScaleBy::create(time, scaleX, scaleY), nullptr);

													
			time = 0.09;

			auto sq2 = Sequence::create(MoveBy::create(time/2, Point(0, offset)),
				ScaleTo::create(time / 2, 1, 1), nullptr);

			offset = MAX_OFFSET/2;
			time = 0.10;

			scaleX = (size.width + offset) / size.width;
			scaleY = (size.height - offset) / size.height;

			auto sq3 = Sequence::create(MoveBy::create(time, Point(0, - offset)),
				ScaleBy::create(time, scaleX, scaleY), nullptr);

			time = 0.11;

			auto sq4 = Sequence::create(MoveBy::create(time / 2, Point(0, offset)),
				ScaleTo::create(time / 2, 1, 1), nullptr);

			auto sq = Sequence::create(sq1, sq2, sq3, sq4, nullptr);
			sq->setTag(shake_tag);
			this->runAction(sq);
		}
		break;
	case smallStone::stoneAnimateType::ani_cute:
		{
			const int cute_tag = 1112;
			if (this->getActionByTag(cute_tag))
			{
				break;
			}
			Vector<SpriteFrame*> frames;
			for (int i = 0; i <= 4; i++)
			{
				SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteNormal[_imgIndex][i]);
				frames.pushBack(frame);
			}
			Animation * animation = Animation::createWithSpriteFrames(frames, 0.05f);
			Animate * ani = Animate::create(animation);
			ani->setTag(cute_tag);
			this->runAction(ani);
		}
		break;
	case smallStone::stoneAnimateType::ani_whiteEye:
		{
			const int whiteEye_tag = 1113;
			if (this->getActionByTag(whiteEye_tag))
			{
				break;
			}
			SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteNormal[_imgIndex][4]);
			this->setDisplayFrame(frame);
		}
		break;
	default:
		break;
	}
}
