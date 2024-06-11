#include "Controller.h"
#include <Windows.h>
#include <graphics.h>

int main()
{
    Controller c;
    while (1)
    {
        c.Game();
    }
    closegraph();
    return 0;
}