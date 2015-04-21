//
//  stoneMap.cpp
//  xiaochu
//
//  Created by apple on 15/3/12.
//
//

#include "stoneMap.h"

stoneMap::stoneMap()
{

}

stoneMap::~stoneMap()
{

}

Scene* stoneMap::createScene()	{
	auto scene = Scene::create();
	auto layer = stoneMap::create();
	scene->addChild(layer);
	return scene;
}

bool stoneMap::init()
{
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("xiaochu.plist");

	initMap();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(stoneMap::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool stoneMap::onTouchBegan(Touch * pTouch, Event * pEvent)
{
	staSprite = NULL;
	endSprite = NULL;

	if (isTouchEnable) {
		auto location = pTouch->getLocation();// this->convertTouchToNodeSpace(pTouch);
		staSprite = spriteOfPoint(location);
		if (staSprite)
		staSprite->doAnimate(smallStone::stoneAnimateType::ani_cute);
	}
	return isTouchEnable;
}

void stoneMap::initMap()
{
	for (int r = 0; r < ROWS; ++r){
		for (int c = 0; c < COLS; ++c){
			createSprite(r, c);
		}
	}
}

void stoneMap::createSprite(int row, int col)	{

	// �ȴ���һ����˾
	smallStone* spr = smallStone::createStone(row, col);

	// �������䶯��
	Point endPosition = positionOfItem(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
	spr->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT);
	spr->runAction(MoveTo::create(speed, endPosition));
	// ���뵽spriteSheet��,�ȴ�����
	this->addChild(spr);

	// ������Ӧλ�ã�������˾����
	map[row][col] = spr;
}

// �������У���ȡ����ֵ
Point stoneMap::positionOfItem(int row, int col)
{
	float x = mapLBX + (SPRITE_WIDTH + BOADER_WIDTH) * col + SPRITE_WIDTH / 2;
	float y = mapLBY + (SPRITE_WIDTH + BOADER_WIDTH) * row + SPRITE_WIDTH / 2;
	return Point(x, y);
}

smallStone *stoneMap::spriteOfPoint(Point point)
{
	smallStone *spr = NULL;
	Rect rect = Rect(0, 0, 0, 0);
	Size sz;
	sz.height = SPRITE_WIDTH;
	sz.width = SPRITE_WIDTH;

	for (int r = 0; r < ROWS; ++r)	{
		for (int c = 0; c < COLS; ++c)	{
			spr = map[r][c];
			if (spr)	{
				Point pt = spr->convertToNodeSpace(point);

				rect.size = sz;
				if (rect.containsPoint(pt)) {
					return spr;
				}
			}
		}
	}

	return NULL;
}