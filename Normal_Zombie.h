#pragma once
#ifndef NORMAL_ZOMBIE_H
#define NORMAL_ZOMBIE_H
#define MOVEMENT_TYPE 3 //Move Eat Die
#define MOVEMENT_FRAME 20 //动作图片数量
#include <graphics.h>
#include <iostream>
#include <ctime>
#include <random>
#include "Settings.h"
using namespace std;

class Normal_Zombie
{
public:
    Normal_Zombie()
    {
        srand(time(NULL));
        this->life = 1000;
        this->damage = 100;
        this->speed = 1;
        this->ZombieID = 1;
        this->islife = true;
        this->row = rand() % 5 + 1;
        this->col = 9;
        this->x = WINDOW_WIDTH;
        this->y = 30 + (row - 1) * 100;
        this->timer = 0;
    }

    int x, y;//具体坐标
    int row, col;//位于的行列
    int life;//生命值
    int damage;//攻击力
    int speed;//速度
    int ZombieID;//僵尸ID
    int timer; //计时器
    int VectorIndex; //在Vector数组中的第几个
    int CurFrameIndex = 0;  //当前播放到第几张
    bool islife; //是否活着
};

#endif // !NORMAL_ZOMBIE_H



