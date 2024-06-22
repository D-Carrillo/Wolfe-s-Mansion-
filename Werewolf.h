#pragma once
#include "EnemyClass.h"

#ifndef WEREWOLF_H
#define WEREWOLF_H

class Werewolf :
    public EnemyClass
{
    private:
        int loot;
        int clawSize;
    public:
        Werewolf();
        Werewolf(int, int, int, int);
        bool attackFunction(int*, int*);
        int getloot();
        void destroyClaw(int);
        void damageW();
        int randomDamage();
        ~Werewolf();
};


#endif

