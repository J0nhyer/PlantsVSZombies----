#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600
#define PlantCard_WIDTH 50
#define PlantCard_HEIGHT 70
#define ZOMBIES_MOVEMENT_TYPE 3 //Move Eat Die
#define ZOMBIES_MOVEMENT_FRAME 50 //����ͼƬ����
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
    int InitGame();//��ʼ����Ϸ
    void LOADImage();//loadimage����ͼƬ
    int InitMenu();
    void SceneCirculate(IMAGE&);//����Ѳ��
    void putimagePNG(int picture_x, int picture_y, IMAGE* picture);//ȥ��ͼƬ�ڱ�
    void _putimagePNG(int picture_x, int picture_y, IMAGE* picture);//ȥ��ͼƬ�ڱ�
    void SetSunTextStyle();
    void SelectPlantCards();//ѡ��ֲ�￨��
    int getDelay();//�õ�ʱ����

    IMAGE ImgGameBackGround; //��Ϸ����ͼƬ
    IMAGE ImgPlantBar; //ֲ����
    IMAGE ImgInitMenu;
    IMAGE ImgSelectBackGround;
    IMAGE ImgSelectStart;
    IMAGE ImgShovel;
    IMAGE ImgShovelSlot;
    IMAGE ImgPlantCards[17];
    IMAGE ImgBeginGame1;
    IMAGE ImgBeginGame2;
    IMAGE ImgBeginFight;
    IMAGE Plants[17][2][20];//��ֲ��ֲ�ﶯ��ͼƬ���� �ֱ��Ӧֲ��ID, ֲ�ﶯ�����࣬�ö���ͼƬ
    IMAGE Sun[29];
    IMAGE ZombieMoveMent[3][50];
    IMAGE Bullets[17][2]; //ֲ���ӵ��������ӵ���ը���ӵ�
    vector<IMAGE> ImgCards; //ѡ��ֲ�￨Ƭ
    vector<int> PlantsID; //ѡ��ֲ�￨Ƭ��Ӧ��ֲ��ID
    vector<bool> IsEmpty; //�ж������Ƭ�����ǲ��ǿյ�
    char FileName[64];//�ļ�·��
    ExMessage msg;
    LOGFONT f; //������
    char f1Text[8];
    int SelectNumber;
    int FrameIndex[17][2];//ֲ�ﶯ��ͼƬ���� [][0]��ҡ�� [][1]�Ƿ���
};

#endif // !SETTINGS_H


