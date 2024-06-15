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
#include "Tools.h"
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <vector>
#include <iostream>
using namespace std;

class Settings
{
public:
    Settings()
    {
        this->IsEmpty.assign(8, true);
        this->SelectNumber = 0;
        this->FrameIndex[0][0] = 13;
        this->FrameIndex[1][0] = 18;
        this->FrameIndex[2][0] = 1;
        this->FrameIndex[3][0] = 1;
        this->FrameIndex[4][0] = 1;
        this->FrameIndex[5][0] = 1;
        this->FrameIndex[6][0] = 1;
        this->FrameIndex[7][0] = 2;
        this->FrameIndex[8][0] = 1;
        this->FrameIndex[9][0] = 1;
        this->FrameIndex[10][0] = 1;
        this->FrameIndex[11][0] = 1;
        this->FrameIndex[12][0] = 1;
        this->FrameIndex[13][0] = 1;
        this->FrameIndex[14][0] = 1;
        this->FrameIndex[15][0] = 1;
        this->FrameIndex[16][0] = 1;
        this->FrameIndex[0][0] = 13;
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
    IMAGE Bullets[17][2]; //植物子弹，正常子弹和炸开子弹
    vector<IMAGE> ImgCards; //选的植物卡片
    vector<int> PlantsID; //选的植物卡片对应的植物ID
    vector<bool> IsEmpty; //判断这个卡片数组是不是空的
    char FileName[64];//文件路径
    ExMessage msg;
    LOGFONT f; //阳光数
    char f1Text[8];
    int SelectNumber;
    int FrameIndex[17][2];//植物动作图片数量 [][0]是摇摆 [][1]是发射
};

#endif // !SETTINGS_H


