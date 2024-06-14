#include "Controller.h"
#include <Windows.h>
#include <graphics.h>

int main()
{
    Controller c;
    c.Game();
    closegraph();
    return 0;
}

//后期优化：
//把关于僵尸的函数调整到Zombies类 植物调到Plants
//修改当前植物状态加载与僵尸类似
//阳光轨迹
