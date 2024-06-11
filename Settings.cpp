//#define _CRT_SECURE_NO_WARNINGS
#include "Settings.h"
#include "Tools.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Settings::InitGame()
{
    LOADImage();
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, 1);
    putimage(0, 0, &ImgGameBackGround);
    //Sleep(2000);
    SceneCirculate(ImgGameBackGround);
    SetSunTextStyle();
    //mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
    putimagePNG(250 + ADJUSTNUM, 0, &ImgPlantBar);
}

void Settings::LOADImage()
{
    loadimage(&ImgGameBackGround, "res/Map/map0.jpg");
    loadimage(&ImgPlantBar, "res/bar4.png");
    //阳光旋转
    for (int i = 1; i <= 29; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/sunshine/%d.png", i);
        loadimage(Sun + i - 1, FileName);
    }
    //豌豆动作
    for (int i = 1; i <= 13; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/zhiwu/0/%d.png", i);
        loadimage(Plants[0] + i - 1, FileName);
    }
    //向日葵动作
    for (int i = 1; i <= 18; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/zhiwu/1/%d.png", i);
        loadimage(Plants[1] + i - 1, FileName);
    }
}

void Settings::SceneCirculate(IMAGE& ImgGameBackGround)
{
    int tmp_x;
    long long ncount;
    for (tmp_x = 0; tmp_x >= WINDOW_WIDTH - ImgGameBackGround.getwidth();tmp_x--)
    {
        BeginBatchDraw();
        putimage(tmp_x, 0, &ImgGameBackGround);
        //for (ncount = 0; ncount <= 10000000; ncount++);
        EndBatchDraw();
    }

    //选植物和显示僵尸功能待实现

    for (tmp_x = WINDOW_WIDTH - ImgGameBackGround.getwidth(); tmp_x <= ADJUSTNUM;tmp_x++)
    {
        putimage(tmp_x, 0, &ImgGameBackGround);
        //for (ncount = 0; ncount <= 10000000; ncount++);
    }
}

void Settings::_putimagePNG(int  picture_x, int picture_y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{
    DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
    DWORD* draw = GetImageBuffer();
    DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
    int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
    int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
    int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
    int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
    int dstX = 0;    //在显存里像素的角标

    // 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
    for (int iy = 0; iy < picture_height; iy++)
    {
        for (int ix = 0; ix < picture_width; ix++)
        {
            int srcX = ix + iy * picture_width; //在显存里像素的角标
            int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
            int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
            int sg = ((src[srcX] & 0xff00) >> 8);   //G
            int sb = src[srcX] & 0xff;              //B
            if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
            {
                dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
                int dr = ((dst[dstX] & 0xff0000) >> 16);
                int dg = ((dst[dstX] & 0xff00) >> 8);
                int db = dst[dstX] & 0xff;
                draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)
                    | ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)
                    | (sb * sa / 255 + db * (255 - sa) / 255);
            }
        }
    }
}

void Settings::SetSunTextStyle()
{
    gettextstyle(&f);                     // 获取当前字体设置
    f.lfHeight = 30;                      // 设置字体高度为 30
    f.lfWidth = 15;
    strcpy(f.lfFaceName, "Segoe UI Black");
    f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
    settextstyle(&f);                     // 设置字体样式
    setbkmode(TRANSPARENT);
    setcolor(BLACK);
}


// 适用于 y <0 以及x<0的任何情况
void Settings::putimagePNG(int x, int y, IMAGE* picture) {

    IMAGE imgTmp, imgTmp2, imgTmp3;
    int winWidth = getwidth();
    int winHeight = getheight();
    if (y < 0) {
        SetWorkingImage(picture);
        getimage(&imgTmp, 0, -y,
            picture->getwidth(), picture->getheight() + y);
        SetWorkingImage();
        y = 0;
        picture = &imgTmp;
    }
    else if (y >= getheight() || x >= getwidth()) {
        return;
    }
    else if (y + picture->getheight() > winHeight) {
        SetWorkingImage(picture);
        getimage(&imgTmp, x, y, picture->getwidth(), winHeight - y);
        SetWorkingImage();
        picture = &imgTmp;
    }

    if (x < 0) {
        SetWorkingImage(picture);
        getimage(&imgTmp2, -x, 0, picture->getwidth() + x, picture->getheight());
        SetWorkingImage();
        x = 0;
        picture = &imgTmp2;
    }

    if (x > winWidth - picture->getwidth()) {
        SetWorkingImage(picture);
        getimage(&imgTmp3, 0, 0, winWidth - x, picture->getheight());
        SetWorkingImage();
        picture = &imgTmp3;
    }


    _putimagePNG(x, y, picture);
}

int Settings::getDelay() {
    static unsigned long long lastTime = 0;
    unsigned long long currentTime = GetTickCount();
    if (lastTime == 0) {
        lastTime = currentTime;
        return 0;
    }
    else {
        int ret = currentTime - lastTime;
        lastTime = currentTime;
        return ret;
    }
}
