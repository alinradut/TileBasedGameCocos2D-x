//
//  HelloWorldScene.cpp
//  TileBasedGame
//
//  Created by Clawoo on 8/17/11.
//  Copyright __MyCompanyName__ 2011. All rights reserved.
//

#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::node();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

HelloWorld::~HelloWorld()
{
    if (_tileMap != NULL)
    {
        _tileMap->release();
        _tileMap = NULL;
    }
    if (_background != NULL)
    {
        _background->release();
        _background = NULL;
    }
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	_tileMap = CCTMXTiledMap::tiledMapWithTMXFile("TileMap.tmx");
    _tileMap->retain();
    
	_background = _tileMap->layerNamed("Background");
    _background->retain();
    
    this->addChild(_tileMap);
	return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}
