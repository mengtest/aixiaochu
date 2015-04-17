//
//  stoneMap.h
//  xiaochu
//
//  Created by apple on 15/3/12.
//
//

#ifndef __xiaochu__stoneMap__
#define __xiaochu__stoneMap__

#include "cocos2d.h"
#include "smallStone.h"
USING_NS_CC;

class stoneMap :public Layer
{
public:
	static Scene*  createScene();
	CREATE_FUNC(stoneMap);
	stoneMap();
	~stoneMap();
private:
	virtual bool init();
	void initMap();
	void createSprite(int row, int col);
	Point positionOfItem(int row, int col);

	bool onTouchBegan(Touch * pTouch,Event * pEvent);

	smallStone *spriteOfPoint(Point point);
private:
	// 绘图的最下角坐标位置
	float mapLBX, mapLBY;

	// 地图二维数组
	smallStone* map[ROWS][COLS];
	smallStone * staSprite;
	smallStone * endSprite;

	bool isTouchEnable;
};

#endif /* defined(__xiaochu__stoneMap__) */

