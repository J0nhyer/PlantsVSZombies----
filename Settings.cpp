//#define _CRT_SECURE_NO_WARNINGS
#include "Settings.h"


int Settings::InitGame()
{
    LOADImage();
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, 1);
    int ret = InitMenu();
    if (ret)
    {
        putimage(0, 0, &ImgGameBackGround);
        //Sleep(2000);
        SceneCirculate(ImgGameBackGround);
        SetSunTextStyle();
        //mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
        putimagePNG(250 + ADJUSTNUM, 0, &ImgPlantBar);
        return 1;
    }   
    return 0;
}

void Settings::LOADImage()
{
    loadimage(&ImgGameBackGround, "res/Map/map0.jpg");
    loadimage(&ImgPlantBar, "res/bar4.png");
    loadimage(&ImgInitMenu, "res/menu.png");
    loadimage(&ImgBeginGame1, "res/menu2.png");
    loadimage(&ImgBeginGame2, "res/menu1.png");
    loadimage(&ImgSelectBackGround, "res/Screen/PanelBackground.png");
    loadimage(&ImgSelectStart, "res/Screen/StartButton.png");
    loadimage(&ImgShovel, "res/Screen/shovel.png", 55, 55);
    loadimage(&ImgShovelSlot, "res/Screen/shovelslot.png", 90, 90);
    loadimage(&ImgBeginFight, "res/Screen/StartButton.png");
    //������ת
    for (int i = 1; i <= 29; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/sunshine/%d.png", i);
        loadimage(Sun + i - 1, FileName);
    }
    //����ֲ�￨Ƭ
    for (int i = 1; i <= 17;i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/Cards/Card_%d.png", i);
        loadimage(ImgPlantCards + i - 1, FileName, PlantCard_WIDTH, PlantCard_HEIGHT);
    }
    //�㶹����
    for (int i = 1; i <= 13; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/zhiwu/0/%d.png", i);
        loadimage(Plants[0][0] + i - 1, FileName);
    }
    //�㶹����
    for (int i = 1; i <= 13; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/zhiwu/0/%d.png", i);
        loadimage(Plants[0][1] + i - 1, FileName);
    }
    //�㶹�ӵ�
    sprintf_s(FileName, sizeof(FileName), "res/bullets/bullet_normal.png");
    loadimage(&Bullets[0][0], FileName);
    sprintf_s(FileName, sizeof(FileName), "res/bullets/bullet_blast.png");
    loadimage(&Bullets[0][1], FileName);
    //���տ�����
    for (int i = 1; i <= 18; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/zhiwu/1/%d.png", i);
        loadimage(Plants[1][0] + i - 1, FileName);
    }
    //ʳ�˻� 2
    sprintf_s(FileName, sizeof(FileName), "res/Plants/Chomper/0.gif");
    loadimage(Plants[2][0], FileName);
    //ӣ��ը�� 3
    sprintf_s(FileName, sizeof(FileName), "res/Plants/CherryBomb/0.gif");
    loadimage(Plants[3][0], FileName);
    //�Ȼ� 4
    sprintf_s(FileName, sizeof(FileName), "res/Plants/HypnoShroom/0.gif");
    loadimage(Plants[4][0], FileName);
    //������ 5
    sprintf_s(FileName, sizeof(FileName), "res/Plants/IceShroom/0.gif");
    loadimage(Plants[5][0], FileName);
    //������ 6
    sprintf_s(FileName, sizeof(FileName), "res/Plants/Jalapeno/0.gif");
    loadimage(Plants[6][0], FileName);
    //������ 7
    sprintf_s(FileName, sizeof(FileName), "res/Plants/PotatoMine/0.gif");
    loadimage(&Plants[7][0][1], FileName);
    sprintf_s(FileName, sizeof(FileName), "res/Plants/PotatoMine/1.gif");
    loadimage(&Plants[7][0][0], FileName);
    //С�繽 8
    sprintf_s(FileName, sizeof(FileName), "res/Plants/PuffShroom/0.gif");
    loadimage(Plants[8][0], FileName);
    //˫������ 9
    sprintf_s(FileName, sizeof(FileName), "res/Plants/Repeater/0.gif");
    loadimage(Plants[9][0], FileName);
    //��С�� 10
    sprintf_s(FileName, sizeof(FileName), "res/Plants/ScaredyShroom/0.gif");
    loadimage(Plants[10][0], FileName);
    //�������� 11
    sprintf_s(FileName, sizeof(FileName), "res/Plants/SnowPea/0.gif");
    loadimage(Plants[11][0], FileName);
    //�ش� 12
    sprintf_s(FileName, sizeof(FileName), "res/Plants/Spikeweed/1.png");
    loadimage(Plants[12][0], FileName);
    //�ѹ� 13
    sprintf_s(FileName, sizeof(FileName), "res/Plants/Squash/2.jpg");
    loadimage(Plants[13][0], FileName);
    //���⹽ 14
    sprintf_s(FileName, sizeof(FileName), "res/Plants/SunShroom/0.gif");
    loadimage(Plants[14][0], FileName);
    //�������� 15
    sprintf_s(FileName, sizeof(FileName), "res/Plants/Threepeater/0.gif");
    loadimage(Plants[15][0], FileName);
    //���� 16
    sprintf_s(FileName, sizeof(FileName), "res/Plants/WallNut/0.gif");
    loadimage(Plants[16][0], FileName);
    //��ʬ�ƶ�  
    for (int i = 1; i <= 22; i++)
    {
        sprintf_s(FileName, sizeof(FileName), "res/zm/%d.png", i);
        loadimage(ZombieMoveMent[0] + i - 1, FileName);
    }
  
}

int Settings::InitMenu()
{
    bool flag = true;
    gettextstyle(&f);                     // ��ȡ��ǰ��������
    f.lfHeight = 30;                      // ��������߶�Ϊ 30
    f.lfWidth = 15;
    strcpy(f.lfFaceName, "Segoe UI Black");
    f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����
    settextstyle(&f);                     // ����������ʽ
    setbkmode(TRANSPARENT);
    setcolor(BLACK);

    while (1)
    {
        BeginBatchDraw();
        putimage(0, 0, &ImgInitMenu);
        putimagePNG(474, 75, flag ? &ImgBeginGame1 : &ImgBeginGame2);
        sprintf_s(f1Text, sizeof(f1Text), "%s", "����");
        outtextxy(660, 483, f1Text);
        sprintf_s(f1Text, sizeof(f1Text), "%s", "��԰");
        outtextxy(735, 505, f1Text);
        sprintf_s(f1Text, sizeof(f1Text), "%s", "�˳�");
        outtextxy(815, 505, f1Text);
        if (peekmessage(&msg))
        {
            if (msg.message == WM_LBUTTONDOWN)
            {
                if (msg.x >= 474 && msg.x <= 474 + 300 && msg.y >= 75 && msg.y <= 75 + 140)
                {
                    EndBatchDraw();
                    return 1;
                }
                else if (msg.x >= 815 && msg.x <= 875 && msg.y >= 505 && msg.y <= 535)
                {
                    EndBatchDraw();
                    return 0;
                }
            }
            else if (msg.message == WM_MOUSEMOVE)
            {
                if (msg.x >= 474 && msg.x <= 474 + 300 && msg.y >= 75 && msg.y <= 75 + 140)
                {
                    flag = false;
                }
                else
                {
                    flag = true;
                }
            }
        }
        EndBatchDraw();
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

    SelectPlantCards();
    //ѡֲ�����ʾ��ʬ���ܴ�ʵ��

    for (tmp_x = WINDOW_WIDTH - ImgGameBackGround.getwidth(); tmp_x <= ADJUSTNUM;tmp_x++)
    {
        BeginBatchDraw();
        putimage(tmp_x, 0, &ImgGameBackGround);
        //for (ncount = 0; ncount <= 10000000; ncount++);
        EndBatchDraw();
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

void Settings::SetSunTextStyle() //����SunText���������������ö�д�����͸�������
{
    gettextstyle(&f);                     // ��ȡ��ǰ��������
    f.lfHeight = 25;                      // ��������߶�Ϊ 30
    f.lfWidth = 12;
    strcpy(f.lfFaceName, "Segoe UI Black");
    f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
    settextstyle(&f);                     // ����������ʽ
    setbkmode(TRANSPARENT);
    setcolor(BLACK);
}

void Settings::SelectPlantCards()
{
    //loadimage(&plantcards[PlantCardIndex].img, "res/Cards/card_1.png", PlantCard_WIDTH, PlantCard_HEIGHT);
    //FrameIndex[PlantCardIndex] = 13;
    //plantcards[PlantCardIndex].status = 0;//�����ƶ�����ѡ���㶹
    //plantcards[PlantCardIndex].FrameIndex = FrameIndex[PlantCardIndex];
    //PlantCardIndex++;
    //loadimage(&plantcards[PlantCardIndex].img, "res/Cards/card_2.png", PlantCard_WIDTH, PlantCard_HEIGHT);
    //FrameIndex[PlantCardIndex] = 18;
    //plantcards[PlantCardIndex].status = 1;
    //plantcards[PlantCardIndex].FrameIndex = FrameIndex[PlantCardIndex];
    //PlantCardIndex++;
    while (1)
    {
        BeginBatchDraw();
        putimagePNG(0, 85, &ImgSelectBackGround);
        putimagePNG(0, 0, &ImgPlantBar);
        putimagePNG(600, 20, ZombieMoveMent[0]);
        putimagePNG(720, 220, ZombieMoveMent[0]);
        putimagePNG(680, 320, ZombieMoveMent[0]);
        putimagePNG(530, 240, ZombieMoveMent[0]);
        putimagePNG(560, 350, ZombieMoveMent[0]);
        putimagePNG(550, 120, ZombieMoveMent[0]);
        putimagePNG(690, 420, ZombieMoveMent[0]);
        putimagePNG(22 + PlantCard_WIDTH * 0 + 3 * 0, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[0]);
        putimagePNG(22 + PlantCard_WIDTH * 1 + 3 * 1, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[1]);
        putimagePNG(22 + PlantCard_WIDTH * 2 + 3 * 2, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[2]);
        putimagePNG(22 + PlantCard_WIDTH * 3 + 3 * 3, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[3]);
        putimagePNG(22 + PlantCard_WIDTH * 4 + 3 * 4, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[4]);
        putimagePNG(22 + PlantCard_WIDTH * 5 + 3 * 5, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[5]);
        putimagePNG(22 + PlantCard_WIDTH * 6 + 3 * 6, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[6]);
        putimagePNG(22 + PlantCard_WIDTH * 7 + 3 * 7, 126 + PlantCard_HEIGHT * 0 + 3 * 0, &ImgPlantCards[7]);
        putimagePNG(22 + PlantCard_WIDTH * 0 + 3 * 0, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[8]);
        putimagePNG(22 + PlantCard_WIDTH * 1 + 3 * 1, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[9]);
        putimagePNG(22 + PlantCard_WIDTH * 2 + 3 * 2, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[10]);
        putimagePNG(22 + PlantCard_WIDTH * 3 + 3 * 3, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[11]);
        putimagePNG(22 + PlantCard_WIDTH * 4 + 3 * 4, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[12]);
        putimagePNG(22 + PlantCard_WIDTH * 5 + 3 * 5, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[13]);
        putimagePNG(22 + PlantCard_WIDTH * 6 + 3 * 6, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[14]);
        putimagePNG(22 + PlantCard_WIDTH * 7 + 3 * 7, 126 + PlantCard_HEIGHT * 1 + 3 * 1, &ImgPlantCards[15]);
        putimagePNG(22 + PlantCard_WIDTH * 0 + 3 * 0, 126 + PlantCard_HEIGHT * 2 + 3 * 2, &ImgPlantCards[16]);
        if (ImgCards.size() == 8)
        {
            putimagePNG(154, 545, &ImgBeginFight);
        }
        for (int i = 0; i < ImgCards.size(); i++)
        {
            putimagePNG(80 + 4 * i + PlantCard_WIDTH * i, 8, ImgCards.data() + i);
        }
        if (peekmessage(&msg))
        {
            if (msg.message == WM_LBUTTONDOWN)
            {
                if (ImgCards.size() < 8)
                {
                    if (msg.x >= 22 + PlantCard_WIDTH * 0 + 3 * 0 && msg.x <= 22 + PlantCard_WIDTH * 1 + 3 * 0 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[0]);
                        PlantsID.emplace_back(0);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 1 + 3 * 1 && msg.x <= 22 + PlantCard_WIDTH * 2 + 3 * 1 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[1]);
                        PlantsID.emplace_back(1);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 2 + 3 * 2 && msg.x <= 22 + PlantCard_WIDTH * 3 + 3 * 2 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[2]);
                        PlantsID.emplace_back(2);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 3 + 3 * 3 && msg.x <= 22 + PlantCard_WIDTH * 4 + 3 * 3 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[3]);
                        PlantsID.emplace_back(3);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 4 + 3 * 4 && msg.x <= 22 + PlantCard_WIDTH * 5 + 3 * 4 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[4]);
                        PlantsID.emplace_back(4);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 5 + 3 * 5 && msg.x <= 22 + PlantCard_WIDTH * 6 + 3 * 5 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[5]);
                        PlantsID.emplace_back(5);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 6 + 3 * 6 && msg.x <= 22 + PlantCard_WIDTH * 7 + 3 * 6 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[6]);
                        PlantsID.emplace_back(6);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 7 + 3 * 7 && msg.x <= 22 + PlantCard_WIDTH * 8 + 3 * 7 && msg.y >= 126 + PlantCard_HEIGHT * 0 + 3 * 0 && msg.y <= 126 + PlantCard_HEIGHT * 1 + 3 * 0)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[7]);
                        PlantsID.emplace_back(7);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 0 + 3 * 0 && msg.x <= 22 + PlantCard_WIDTH * 1 + 3 * 0 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[8]);
                        PlantsID.emplace_back(8);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 1 + 3 * 1 && msg.x <= 22 + PlantCard_WIDTH * 2 + 3 * 1 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[9]);
                        PlantsID.emplace_back(9);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 2 + 3 * 2 && msg.x <= 22 + PlantCard_WIDTH * 3 + 3 * 2 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[10]);
                        PlantsID.emplace_back(10);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 3 + 3 * 3 && msg.x <= 22 + PlantCard_WIDTH * 4 + 3 * 3 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[11]);
                        PlantsID.emplace_back(11);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 4 + 3 * 4 && msg.x <= 22 + PlantCard_WIDTH * 5 + 3 * 4 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[12]);
                        PlantsID.emplace_back(12);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 5 + 3 * 5 && msg.x <= 22 + PlantCard_WIDTH * 6 + 3 * 5 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[13]);
                        PlantsID.emplace_back(13);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 6 + 3 * 6 && msg.x <= 22 + PlantCard_WIDTH * 7 + 3 * 6 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[14]);
                        PlantsID.emplace_back(14);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 7 + 3 * 7 && msg.x <= 22 + PlantCard_WIDTH * 8 + 3 * 7 && msg.y >= 126 + PlantCard_HEIGHT * 1 + 3 * 1 && msg.y <= 126 + PlantCard_HEIGHT * 2 + 3 * 1)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[15]);
                        PlantsID.emplace_back(15);
                    }
                    else if (msg.x >= 22 + PlantCard_WIDTH * 0 + 3 * 0 && msg.x <= 22 + PlantCard_WIDTH * 1 + 3 * 0 && msg.y >= 126 + PlantCard_HEIGHT * 2 + 3 * 2 && msg.y <= 126 + PlantCard_HEIGHT * 3 + 3 * 2)
                    {
                        IsEmpty[ImgCards.size()] = false;
                        ImgCards.emplace_back(ImgPlantCards[16]);
                        PlantsID.emplace_back(16);
                    }
                }
                if (ImgCards.size() > 0)
                {
                    if (msg.x >= 80 + 4 * 0 + PlantCard_WIDTH * 0 && msg.x <= 80 + 4 * 0 + PlantCard_WIDTH * 1 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[0])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 0);
                        }
                    }
                    else if (msg.x >= 80 + 4 * 1 + PlantCard_WIDTH * 1 && msg.x <= 80 + 4 * 1 + PlantCard_WIDTH * 2 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[1])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 1);
                        }
                    }
                    else if (msg.x >= 80 + 4 * 2 + PlantCard_WIDTH * 2 && msg.x <= 80 + 4 * 2 + PlantCard_WIDTH * 3 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[2])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 2);
                        }
                    }
                    else if (msg.x >= 80 + 4 * 3 + PlantCard_WIDTH * 3 && msg.x <= 80 + 4 * 3 + PlantCard_WIDTH * 4 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[3])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 3);
                        }
                    }
                    else if (msg.x >= 80 + 4 * 4 + PlantCard_WIDTH * 4 && msg.x <= 80 + 4 * 4 + PlantCard_WIDTH * 5 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[4])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 4);
                        }
                    }
                    else if (msg.x >= 80 + 4 * 5 + PlantCard_WIDTH * 5 && msg.x <= 80 + 4 * 5 + PlantCard_WIDTH * 6 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[5])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 5);
                        }
                    }
                    else if (msg.x >= 80 + 4 * 6 + PlantCard_WIDTH * 6 && msg.x <= 80 + 4 * 6 + PlantCard_WIDTH * 7 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[6])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 6);
                        }
                    }
                    else if (msg.x >= 80 + 4 * 7 + PlantCard_WIDTH * 7 && msg.x <= 80 + 4 * 7 + PlantCard_WIDTH * 8 && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                    {
                        if (!IsEmpty[7])
                        {
                            IsEmpty[ImgCards.size() - 1] = true;
                            ImgCards.erase(ImgCards.begin() + 7);
                        }
                    }
                }
                if (ImgCards.size() == 8)
                {
                    if (msg.x >= 154 && msg.x <= 154 + 154 && msg.y >= 545 && msg.y <= 545 + 37)
                    {
                        break;
                    }
                }
            }
        }
        EndBatchDraw();
    }
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
