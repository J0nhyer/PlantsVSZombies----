#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Settings.h"
#include "Sun.h"
#include <graphics.h>
#include <random>
#include <ctime>
#include <cmath>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

struct PlantCards
{
    //int PlantCardIndex;//植物卡片是选的1-8张的第i-1张
    int status = -1; //植物ID
    int FrameIndex = 0; //一共有多少张动图
    IMAGE img;
};

struct Map
{
    int status = -1; //植物ID
    int CurFrameIndex = 0;  //当前播放到第几张
    int timer = 0;//计时器
};

class Controller
{
public:
    Controller()//构造函数初始化数据
    {
        this->PlantCardIndex = 0;
        this->PlantCardIndex1 = 0;
        this->status = -1;
        this->MapPlantNumber = 0;
        this->timer = 98000;
        this->sun_status = false;
        this->collect_sun_status = false;
        this->sun_FrameIndex = 29;
        this->sun_CurFrameIndex = 0;
        this->timer1 = 0;
        this->sun_num = 50;
        this->sunText[8] = { NULL };
    }
    void Game();//游戏主体
    void UpdateGame();//渲染游戏
    void SelectPlantCards();//选择植物卡牌
    void ShowPlantCards();//展示植物卡牌
    void MovePlantCards();//从卡牌处移动植物
    bool IsPlanting();//是否可以种植
    void Planting();//种植植物
    void PlantSwing();//植物摇摆
    void ProductSun();//产生阳光
    void FallSun();//阳光下落
    void CollectSun();//收集阳光
    void UpdateSun();//更新阳光数量
    void ShowSun();//显示阳光数量

    Settings setting;//使用Settings功能
    PlantCards plantcards[8];
    ExMessage msg;//鼠标状态
    Map map[5][9];//地图
    int status;//当前鼠标选择的植物ID
    int FrameIndex[2];//植物摇摆图片数量
    int sun_FrameIndex; //阳光图片数量
    int sun_CurFrameIndex; //当前播放到第几张
    int PlantCardIndex, PlantCardIndex1;//植物卡片是选的1-8张的第i-1张
    int MapPlantNumber;//得到当前已经种植的植物的数量，最初的目的是为了减少多放植物引起的卡顿
    int timer, timer1;//计时器
    int sun_x, sun_y, tmp_sun_y; //阳光坐标
    int distance_x, distance_y; //计算拖动卡牌时，鼠标和卡牌边框的距离
    int sun_num; //收集到的阳光数量
    bool sun_status; //是否下落阳光
    bool collect_sun_status; //是否收集阳光
    char sunText[8]; //阳光文本
};

#endif // !CONTROLLER_H



