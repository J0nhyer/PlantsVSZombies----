#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600
#define PlantCard_WIDTH 52
#define PlantCard_HEIGHT 68
#define CardDistance 
#define ADJUSTNUM -130
#include <graphics.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class Settings
{
public:
    void InitGame();//��ʼ����Ϸ
    void LOADImage();//loadimage����ͼƬ
    void SceneCirculate(IMAGE&);//����Ѳ��
    void putimagePNG(int picture_x, int picture_y, IMAGE* picture);//ȥ��ͼƬ�ڱ�
    void _putimagePNG(int picture_x, int picture_y, IMAGE* picture);//ȥ��ͼƬ�ڱ�
    void SetSunTextStyle();
    int getDelay();//�õ�ʱ����

    IMAGE ImgGameBackGround; //��Ϸ����ͼƬ
    IMAGE ImgPlantBar; //ֲ����
    IMAGE Plants[2][20];//��ֲ��ֲ�ﶯ��ͼƬ����
    IMAGE Sun[29];
    char FileName[128];//�ļ�·��
    LOGFONT f;
};

#endif // !SETTINGS_H


