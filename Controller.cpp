#include "Controller.h"

void Controller::Game()
{
    srand(time(NULL));
    setting.InitGame();
    SelectPlantCards();
    while (1)
    {
        UpdateGame();
    }
}

void Controller::UpdateGame()
{
    BeginBatchDraw();
    putimage(ADJUSTNUM, 0, &setting.ImgGameBackGround);
    setting.putimagePNG(250 + ADJUSTNUM, 0, &setting.ImgPlantBar);
    ShowPlantCards();
    PlantSwing();
    if (status + 1)
    {
        //cout << PlantCardIndex1 << endl;
        setting.putimagePNG(msg.x - distance_x, msg.y - distance_y, setting.Plants[status]);
    }
    MovePlantCards();
    timer += setting.getDelay();
    if (timer >= 5000)
    {
        timer = 0;
        ProductSun();
    }
    if (sun_status)
    {
        FallSun();
    }
    ShowSun();
    if (collect_sun_status)
    {
        CollectSun();
    }
    EndBatchDraw();
}

void Controller::SelectPlantCards()
{
    loadimage(&plantcards[PlantCardIndex].img, "res/Cards/card_1.png", PlantCard_WIDTH, PlantCard_HEIGHT);
    FrameIndex[PlantCardIndex] = 13;
    plantcards[PlantCardIndex].status = 0;//待完善都是先选择豌豆
    plantcards[PlantCardIndex].FrameIndex = FrameIndex[PlantCardIndex];
    PlantCardIndex++;
    loadimage(&plantcards[PlantCardIndex].img, "res/Cards/card_2.png", PlantCard_WIDTH, PlantCard_HEIGHT);
    FrameIndex[PlantCardIndex] = 18;
    plantcards[PlantCardIndex].status = 1;
    plantcards[PlantCardIndex].FrameIndex = FrameIndex[PlantCardIndex];
    PlantCardIndex++;
}

void Controller::ShowPlantCards()
{
    PlantCardIndex = 0;
    setting.putimagePNG(328 + 2 * PlantCardIndex + PlantCard_WIDTH * PlantCardIndex + ADJUSTNUM, 9, &plantcards[PlantCardIndex].img);
    PlantCardIndex++;
    setting.putimagePNG(328 + 2 * PlantCardIndex + PlantCard_WIDTH * PlantCardIndex + ADJUSTNUM, 9, &plantcards[PlantCardIndex].img);
    PlantCardIndex++;
}

void Controller::MovePlantCards()
{
    if (peekmessage(&msg))
    {
        switch (msg.message)
        {
        case WM_LBUTTONDOWN:
            if (msg.x >= sun_x && msg.x <= sun_x + 79 && msg.y >= sun_y && msg.y <= sun_y + 79)//先判断是否拾取到阳光
            {
                collect_sun_status = true;
                sun_num += 25;
                //mciSendString("play res/sunshine.mp3", 0, 0, 0);
            }
            if ((&plantcards[0].img != NULL) && msg.x >= (328 + 2 * 0 + PlantCard_WIDTH * 0 + ADJUSTNUM) && msg.x <= (328 + 2 * 0 + PlantCard_WIDTH * 1 + ADJUSTNUM) && msg.y >= 9 && msg.y <= 8 + PlantCard_HEIGHT)
            {
                //这边是粗糙功能待完善，只是把豌豆当作第一个必选                
                setting.putimagePNG(328 + 2 * 0 + PlantCard_WIDTH * 0 + ADJUSTNUM, 9, setting.Plants[plantcards[0].status]);
                status = plantcards[0].status;
                PlantCardIndex1 = 0;
                distance_x = msg.x - (328 + 2 * PlantCardIndex1 + PlantCard_WIDTH * PlantCardIndex1 + ADJUSTNUM);
                distance_y = msg.y - 9;

            }
            if ((&plantcards[1].img != NULL) && msg.x >= (328 + 2 * 1 + PlantCard_WIDTH * 1 + ADJUSTNUM) && msg.x <= (328 + 2 * 1 + PlantCard_WIDTH * 2 + ADJUSTNUM) && msg.y >= 9 && msg.y <= 8 + PlantCard_HEIGHT)
            {
                setting.putimagePNG(328 + 2 * 1 + PlantCard_WIDTH * 1 + ADJUSTNUM, 9, setting.Plants[plantcards[1].status]);
                status = plantcards[1].status;
                PlantCardIndex1 = 1;
                distance_x = msg.x - (328 + 2 * PlantCardIndex1 + PlantCard_WIDTH * PlantCardIndex1 + ADJUSTNUM);
                distance_y = msg.y - 9;
            }
            break;
 
        //case WM_MOUSEMOVE:
        //    if (status)
        //    {
        //        setting.putimagePNG(msg.x, msg.y, PlantCards + PlantCardIndex);
        //    }
        //    break;
            
        case WM_LBUTTONUP:
            if (IsPlanting() && (status + 1))
            {
                Planting();
            }
            else if (status + 1)
            {
                status = -1;
            }
            break;

        default:
            break;
        }
    }
}

bool Controller::IsPlanting()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (msg.x >= 250 + j * 80 + ADJUSTNUM && msg.x <= 250 + (j + 1) * 80 + ADJUSTNUM && msg.y >= 75 + i * 90 && msg.y <= 75 + (i + 1) * 90 && (map[i][j].status == -1))
            {
                map[i][j].status = status;
                return true;
            }
        }
    }
    return false;
}

void Controller::Planting()
{
    status = -1;
    MapPlantNumber++;
    cout << 1 << endl; 
    mciSendString("play res/audio/plant1.mp3", 0, 0, 0);
}

void Controller::PlantSwing()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (map[i][j].status != -1)
            {
                setting.putimagePNG(260 + j * 80 + ADJUSTNUM, 80 + i * 100, &setting.Plants[map[i][j].status][map[i][j].CurFrameIndex]);
                map[i][j].timer++;
                if ((map[i][j].timer >= 50 * (48 - MapPlantNumber) * 0.02))//后期修改参数来减少多放植物的卡顿；
                {
                    map[i][j].timer = 0;
                    map[i][j].CurFrameIndex++;
                    map[i][j].CurFrameIndex %= FrameIndex[map[i][j].status];
                }
            }
        }
    }
}

void Controller::ProductSun()
{
    sun_x = 350 + rand() % 301 + ADJUSTNUM;
    sun_y = 30;
    tmp_sun_y = sun_y;
    sun_status = true;
}

void Controller::FallSun() // x 450-750   y 200-500
{
    if ((sun_y >= 350 + rand() % 60))
    {
        tmp_sun_y++;
        setting.putimagePNG(sun_x, sun_y, &setting.Sun[sun_CurFrameIndex]);
        timer1++;
        if (timer1 >= 15)
        {
            timer1 = 0;
            sun_CurFrameIndex++;
            sun_CurFrameIndex %= sun_FrameIndex;
        }

        if (tmp_sun_y >= 1000)
        {
            sun_x = -100;
            sun_y = 0;
            sun_status = false;
        }
     
    }
    else
    {
        tmp_sun_y++;
        if (tmp_sun_y >= 4)
        {
            tmp_sun_y = 0;
            sun_y++;
        }
        setting.putimagePNG(sun_x, sun_y, &setting.Sun[sun_CurFrameIndex]);
        timer1++;
        if (timer1 >= 15)
        {
            timer1 = 0;
            sun_CurFrameIndex++;
            sun_CurFrameIndex %= sun_FrameIndex;
        }
    }
}

void Controller::CollectSun() // 130   3
{
    double* delta_x = new double;
    double* delta_y = new double;
    double* angle = new double;
    *delta_x = sun_x - 130;
    *delta_y = sun_y - 3;
    *angle = atan(*delta_y / *delta_x);
    if (sun_x >= 130 || sun_y >= 3)
    {
        setting.putimagePNG(sun_x, sun_y, setting.Sun);
        sun_x = (10 * sun_x - 10 * cos(*angle)) / 10;
        sun_y = (10 * sun_y - 10 * sin(*angle)) / 10;
        delete delta_x;
        delete delta_y;
        delete angle;
    }
    else
    {
        collect_sun_status = false;
        delete delta_x;
        delete delta_y;
        delete angle;
    }
}

void Controller::UpdateSun()
{
}

void Controller::ShowSun()
{
    sprintf_s(sunText, sizeof(sunText), "%d", sun_num);
    outtextxy(142, 55, sunText);//后期要调整不同位数居中问题;
}



