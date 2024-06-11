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
    //int PlantCardIndex;//ֲ�￨Ƭ��ѡ��1-8�ŵĵ�i-1��
    int status = -1; //ֲ��ID
    int FrameIndex = 0; //һ���ж����Ŷ�ͼ
    IMAGE img;
};

struct Map
{
    int status = -1; //ֲ��ID
    int CurFrameIndex = 0;  //��ǰ���ŵ��ڼ���
    int timer = 0;//��ʱ��
};

class Controller
{
public:
    Controller()//���캯����ʼ������
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
    void Game();//��Ϸ����
    void UpdateGame();//��Ⱦ��Ϸ
    void SelectPlantCards();//ѡ��ֲ�￨��
    void ShowPlantCards();//չʾֲ�￨��
    void MovePlantCards();//�ӿ��ƴ��ƶ�ֲ��
    bool IsPlanting();//�Ƿ������ֲ
    void Planting();//��ֲֲ��
    void PlantSwing();//ֲ��ҡ��
    void ProductSun();//��������
    void FallSun();//��������
    void CollectSun();//�ռ�����
    void UpdateSun();//������������
    void ShowSun();//��ʾ��������

    Settings setting;//ʹ��Settings����
    PlantCards plantcards[8];
    ExMessage msg;//���״̬
    Map map[5][9];//��ͼ
    int status;//��ǰ���ѡ���ֲ��ID
    int FrameIndex[2];//ֲ��ҡ��ͼƬ����
    int sun_FrameIndex; //����ͼƬ����
    int sun_CurFrameIndex; //��ǰ���ŵ��ڼ���
    int PlantCardIndex, PlantCardIndex1;//ֲ�￨Ƭ��ѡ��1-8�ŵĵ�i-1��
    int MapPlantNumber;//�õ���ǰ�Ѿ���ֲ��ֲ��������������Ŀ����Ϊ�˼��ٶ��ֲ������Ŀ���
    int timer, timer1;//��ʱ��
    int sun_x, sun_y, tmp_sun_y; //��������
    int distance_x, distance_y; //�����϶�����ʱ�����Ϳ��Ʊ߿�ľ���
    int sun_num; //�ռ�������������
    bool sun_status; //�Ƿ���������
    bool collect_sun_status; //�Ƿ��ռ�����
    char sunText[8]; //�����ı�
};

#endif // !CONTROLLER_H



