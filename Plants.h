#pragma once
#ifndef PLANTS_H
#define PLANTS_H
#include "Settings.h"

class Plants
{
public:
    Plants() 
    {
        this->PlantCardIndex = 0;
    }
    
    void PlantAttack(Settings&);

    int x, y;
    int row, col;
    int life; //生命值
    int damage; //攻击力
    int cost; //花费阳光
    int damagespeed; //攻击速度
    int damagerange; //攻击距离(格数)
    int PlantID; //植物ID
    int timer; //计时器
    int PlantCardIndex;//植物卡片是选的1-8张的第i-1张
};

class PeaShooter :public Plants
{
public:
    PeaShooter()
    {
        this->life = 500;
        this->damage = 100;
        this->cost = 100;
        this->damagespeed = 2000;
        this->damagerange = 6;
        this->PlantID = 0;
        this->timer = 0;
    }

};

class SunFlower :public Plants
{
public:
    SunFlower()
    {
        this->life = 400;
        this->cost = 50;
        this->damagespeed = 20000;
        this->damagerange = -1;
        this->PlantID = 1;
        this->timer = 0;
    }

};

#endif // !PLANTS_H


