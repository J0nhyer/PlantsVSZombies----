#pragma once
#ifndef NORMAL_ZOMBIE_H
#define NORMAL_ZOMBIE_H
#define MOVEMENT_TYPE 3 //Move Eat Die
#define MOVEMENT_FRAME 20 //����ͼƬ����
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

    int x, y;//��������
    int row, col;//λ�ڵ�����
    int life;//����ֵ
    int damage;//������
    int speed;//�ٶ�
    int ZombieID;//��ʬID
    int timer; //��ʱ��
    int VectorIndex; //��Vector�����еĵڼ���
    int CurFrameIndex = 0;  //��ǰ���ŵ��ڼ���
    bool islife; //�Ƿ����
};

#endif // !NORMAL_ZOMBIE_H



