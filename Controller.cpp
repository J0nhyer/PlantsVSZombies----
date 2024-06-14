#include "Controller.h"

void Controller::Game()
{
    
    srand(time(NULL));
    int ret = setting.InitGame();
    if (ret)
    {
        while (!ending_flag)
        {
            UpdateGame();
        }
    }
}

void Controller::UpdateGame()
{
    if (IsEnd())
    {
        ending_flag = true;
        return;
    }
    BeginBatchDraw();
    putimage(ADJUSTNUM, 0, &setting.ImgGameBackGround);
    setting.putimagePNG(250 + ADJUSTNUM, 0, &setting.ImgPlantBar);
    setting.putimagePNG(775 + ADJUSTNUM, 0, &setting.ImgShovelSlot);
    setting.putimagePNG(787 + ADJUSTNUM, 15, &setting.ImgShovel);
    ProductZombies();
    ShowPlantCards();
    PlantSwing();
    if (status + 1)
    {
        setting.putimagePNG(msg.x - distance_x, msg.y - distance_y, setting.Plants[status][0]);
    }
    UserInput();
    timer += setting.getDelay();
    if (timer >= 20000)
    {
        timer = 0;
        ProductSun();
    }
    AttackPlants();
    if (sun_status)
    {
        FallSun();
    }
    ShowSun();
    MoveZombies();
    if (collect_sun_status)
    {
        CollectSun();
    } 
    EndBatchDraw();
}

void Controller::ShowPlantCards()
{
    //PlantCardIndex = 0;
    //setting.putimagePNG(328 + 2 * PlantCardIndex + PlantCard_WIDTH * PlantCardIndex + ADJUSTNUM, 9, &plantcards[PlantCardIndex].img);
    //PlantCardIndex++;
    //setting.putimagePNG(328 + 2 * PlantCardIndex + PlantCard_WIDTH * PlantCardIndex + ADJUSTNUM, 9, &plantcards[PlantCardIndex].img);
    //PlantCardIndex++;
    for (int i = 0; i < 8; i++)
    {
        setting.putimagePNG(328 + 4 * i + PlantCard_WIDTH * i + ADJUSTNUM, 8, &setting.ImgCards[i]);
    }
}

void Controller::UserInput()
{
    MovePlantCards();
    KeyBoardInput();
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
                sun_status = false;
                sun_num += 25;
                //mciSendString("play res/sunshine.mp3", 0, 0, 0);
            }
            for (int i = 0; i < 8; i++)
            {
                if (msg.x >= (328 + 4 * i + PlantCard_WIDTH * i + ADJUSTNUM) && msg.x <= (328 + 4 * i + PlantCard_WIDTH * (i + 1) + ADJUSTNUM) && msg.y >= 8 && msg.y <= 8 + PlantCard_HEIGHT)
                {
                    status = setting.PlantsID[i];
                    distance_x = msg.x - (328 + 4 * i + PlantCard_WIDTH * i + ADJUSTNUM);
                    distance_y = msg.y - 8;
                }
            }
            break;
            
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

void Controller::KeyBoardInput()
{
    //int ch;
    //switch (ch)
    //{
    //case 27:
    //    break;
    //}
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
    cout << MapPlantNumber << endl;
    //mciSendString("play res/audio/plant1.mp3", 0, 0, 0);
}

void Controller::PlantSwing()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (map[i][j].status != -1)
            {
                setting.putimagePNG(260 + j * 80 + ADJUSTNUM, 80 + i * 100, setting.Plants[map[i][j].status][0]);
                map[i][j].timer += (MapPlantNumber / 5) + 1;
                if ((map[i][j].timer >= 50))//后期修改参数来减少多放植物的卡顿；
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

        if (tmp_sun_y >= 2700)
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
        if (timer1 >= 25)
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
    if (sun_x >= 130 && sun_y >= 3)
    {
        setting.putimagePNG(sun_x, sun_y, setting.Sun);
        sun_x = (100 * sun_x - 100 * cos(*angle)) / 100;//待优化
        sun_y = (100 * sun_y - 100 * sin(*angle)) / 100;
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

void Controller::ShowSun()
{
    sprintf_s(sunText, sizeof(sunText), "%d", sun_num);
    outtextxy(142, 57, sunText);//后期要调整不同位数居中问题;
}

bool Controller::IsEnd()
{
    return false;
}

void Controller::ProductZombies()
{
    timer2++;
    if (timer2 >= 10000) {
        timer2 = 0;
        //Zombies* zombie = new Zombies;
        zombies.emplace_back();  // 直接在vector中创建Zombies对象
        zombies.back().normal_zombie.VectorIndex = zombies.size() - 1;
    }
}

void Controller::MoveZombies()
{
    for (int i = 0; i < zombies.size(); i++) 
    {
        zombies[i].normal_zombie.timer++;
        setting.putimagePNG(zombies[i].normal_zombie.x, zombies[i].normal_zombie.y, &setting.ZombieMoveMent[0][zombies[i].normal_zombie.CurFrameIndex]);
        if (zombies[i].normal_zombie.timer >= 28)
        {
            zombies[i].normal_zombie.timer = 0;
            zombies[i].normal_zombie.x -= zombies[i].normal_zombie.speed;
            zombies[i].normal_zombie.CurFrameIndex++;
            zombies[i].normal_zombie.CurFrameIndex %= 22;
        }
    }
}

void Controller::AttackPlants()
{
    bool flag = false;//是否有子弹
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if ((map[i][j].status + 1))
            {
                
                flag = true;
            }
        }
    }

    BulletMove();
}

void Controller::BulletMove()
{

}



