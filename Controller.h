#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <graphics.h>
#include <random>
#include <ctime>
#include <cmath>
#include <vector>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "Settings.h"
#include "Zombies.h"
#include "Plants.h"
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
        this->MapZombieNumber = 0;
        this->timer = 98000;
        this->timer1 = 0;
        this->timer2 = 9800;
        this->sun_status = false;
        this->collect_sun_status = false;
        this->sun_FrameIndex = 29;
        this->sun_CurFrameIndex = 0;
        this->sun_num = 50;
        this->zombies.reserve(1000);
        this->ending_flag = false;
    }
    void Game();//��Ϸ����
    void UpdateGame();//��Ⱦ��Ϸ        
    void ShowPlantCards();//չʾֲ�￨��
    void UserInput(); 
    void MovePlantCards();//�ӿ��ƴ��ƶ�ֲ��
    void KeyBoardInput();
    bool IsPlanting();//�Ƿ������ֲ
    void Planting();//��ֲֲ��
    void PlantSwing();//ֲ��ҡ��
    void ProductSun();//��������
    void FallSun();//��������
    void CollectSun();//�ռ�����
    void ShowSun();//��ʾ��������
    bool IsEnd();
    //��ʬ
    void ProductZombies();
    void MoveZombies();
    //ֲ��
    void AttackPlants();
    void BulletMove();

    Settings setting;//ʹ��Settings����
    PlantCards plantcards[8];
    ExMessage msg;//���״̬
    Map map[5][9];//��ͼ
    int status;//��ǰ���ѡ���ֲ��ID
    int FrameIndex[8];//ֲ��ҡ��ͼƬ����
    int sun_FrameIndex; //����ͼƬ����
    int sun_CurFrameIndex; //��ǰ���ŵ��ڼ���
    int PlantCardIndex, PlantCardIndex1;//ֲ�￨Ƭ��ѡ��1-8�ŵĵ�i-1��
    int MapPlantNumber;//�õ���ǰ�Ѿ���ֲ��ֲ��������������Ŀ����Ϊ�˼��ٶ��ֲ������Ŀ���
    int MapZombieNumber; //�õ���ǰ�Ѿ������Ľ�ʬ������
    //int ZombieVectorInde; //��Vector�����еĵڼ���
    int timer, timer1, timer2;//��ʱ��   timer1��������  timer2�ǲ�����ʬ��ʱ��
    int sun_x, sun_y, tmp_sun_y; //��������
    int distance_x, distance_y; //�����϶�����ʱ�����Ϳ��Ʊ߿�ľ���
    int sun_num; //�ռ�������������
    int ch; //��������ָ��
    bool sun_status; //�Ƿ���������
    bool collect_sun_status; //�Ƿ��ռ�����
    bool ending_flag; //������־
    char sunText[8]; //�����ı�
    vector<Zombies> zombies;
};

#endif // !CONTROLLER_H



