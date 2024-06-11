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
    //������ת
    for (int i = 1; i <= 29; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/sunshine/%d.png", i);
        loadimage(Sun + i - 1, FileName);
    }
    //�㶹����
    for (int i = 1; i <= 13; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/zhiwu/0/%d.png", i);
        loadimage(Plants[0] + i - 1, FileName);
    }
    //���տ�����
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

    //ѡֲ�����ʾ��ʬ���ܴ�ʵ��

    for (tmp_x = WINDOW_WIDTH - ImgGameBackGround.getwidth(); tmp_x <= ADJUSTNUM;tmp_x++)
    {
        putimage(tmp_x, 0, &ImgGameBackGround);
        //for (ncount = 0; ncount <= 10000000; ncount++);
    }
}

void Settings::_putimagePNG(int  picture_x, int picture_y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{
    DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
    DWORD* draw = GetImageBuffer();
    DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
    int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
    int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
    int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
    int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
    int dstX = 0;    //���Դ������صĽǱ�

    // ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
    for (int iy = 0; iy < picture_height; iy++)
    {
        for (int ix = 0; ix < picture_width; ix++)
        {
            int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
            int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
            int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
            int sg = ((src[srcX] & 0xff00) >> 8);   //G
            int sb = src[srcX] & 0xff;              //B
            if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
            {
                dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
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
    gettextstyle(&f);                     // ��ȡ��ǰ��������
    f.lfHeight = 30;                      // ��������߶�Ϊ 30
    f.lfWidth = 15;
    strcpy(f.lfFaceName, "Segoe UI Black");
    f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
    settextstyle(&f);                     // ����������ʽ
    setbkmode(TRANSPARENT);
    setcolor(BLACK);
}


// ������ y <0 �Լ�x<0���κ����
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
