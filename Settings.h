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
    void InitGame();//初始化游戏
    void LOADImage();//loadimage加载图片
    void SceneCirculate(IMAGE&);//场景巡回
    void putimagePNG(int picture_x, int picture_y, IMAGE* picture);//去除图片黑边
    void _putimagePNG(int picture_x, int picture_y, IMAGE* picture);//去除图片黑边
    void SetSunTextStyle();
    int getDelay();//得到时间间隔

    IMAGE ImgGameBackGround; //游戏背景图片
    IMAGE ImgPlantBar; //植物栏
    IMAGE Plants[2][20];//种植后植物动作图片数组
    IMAGE Sun[29];
    char FileName[128];//文件路径
    LOGFONT f;
};

#endif // !SETTINGS_H


