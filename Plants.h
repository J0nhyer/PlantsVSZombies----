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
    int life; //����ֵ
    int damage; //������
    int cost; //��������
    int damagespeed; //�����ٶ�
    int damagerange; //��������(����)
    int PlantID; //ֲ��ID
    int timer; //��ʱ��
    int PlantCardIndex;//ֲ�￨Ƭ��ѡ��1-8�ŵĵ�i-1��
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


