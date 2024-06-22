#pragma once
#include "EnemyClass.h"

class Gargoyle :
    public EnemyClass
{
    private:
        int loot;
        int level;
    public:
        Gargoyle();
        Gargoyle(int, int, int, int);
        bool attackFunction(int*, int*);
        bool rearange();
        ~Gargoyle();


};

