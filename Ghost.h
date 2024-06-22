#pragma once
#ifndef GHOST_H
#define GHOST_H
#include "EnemyClass.h"

class Ghost :
    public EnemyClass
{
    private:
        int loot;
    public:
        Ghost();
        Ghost(int, int, int);
        bool hidingGame();
        bool attackFunction(int*, int*);
        int getloot();
        int randomDamage();
        ~Ghost();

};


#endif
