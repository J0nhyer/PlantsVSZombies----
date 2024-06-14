#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600
#define PlantCard_WIDTH 50
#define PlantCard_HEIGHT 70
#define ZOMBIES_MOVEMENT_TYPE 3 //Move Eat Die
#define ZOMBIES_MOVEMENT_FRAME 50 //动作图片数量
#define CardDistance 
#define ADJUSTNUM -130
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <vector>
#include <iostream>
using namespace std;
#include "Tools.h"

class Settings
{
public:
    Settings()
    {
        this->IsEmpty.assign(8, true);
        this->SelectNumber = 0;
    }
    int InitGame();//初始化游戏
    void LOADImage();//loadimage加载图片
    int InitMenu();
    void SceneCirculate(IMAGE&);//场景巡回
    void putimagePNG(int picture_x, int picture_y, IMAGE* picture);//去除图片黑边
    void _putimagePNG(int picture_x, int picture_y, IMAGE* picture);//去除图片黑边
    void SetSunTextStyle();
    void SelectPlantCards();//选择植物卡牌
    int getDelay();//得到时间间隔

    IMAGE ImgGameBackGround; //游戏背景图片
    IMAGE ImgPlantBar; //植物栏
    IMAGE ImgInitMenu;
    IMAGE ImgSelectBackGround;
    IMAGE ImgSelectStart;
    IMAGE ImgShovel;
    IMAGE ImgShovelSlot;
    IMAGE ImgPlantCards[17];
    IMAGE ImgBeginGame1;
    IMAGE ImgBeginGame2;
    IMAGE ImgBeginFight;
    IMAGE Plants[17][2][20];//种植后植物动作图片数组 分别对应植物ID, 植物动作种类，该动作图片
    IMAGE Sun[29];
    IMAGE ZombieMoveMent[3][50];
    IMAGE Bullets[17][2];
    vector<IMAGE> ImgCards; //选的植物卡片
    vector<int> PlantsID; //选的植物卡片对应的植物ID
    vector<bool> IsEmpty; //判断这个卡片数组是不是空的
    char FileName[64];//文件路径
    ExMessage msg;
    LOGFONT f; //阳光数
    char f1Text[8];
    int SelectNumber;
};

#endif // !SETTINGS_H


