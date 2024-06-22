#pragma once

#ifndef ENEMYCLASS_H
#define ENEMYCLASS_H
#include <iostream>
using namespace std;

class EnemyClass
{
    protected:
        int healthBar;
        int AP;

    public:
        EnemyClass();
        EnemyClass(int, int);
        void setAttackPower(int);
        int getAttackPower();
        virtual bool attackFunction(int*, int*);
        void setHealth(int);
        int getHealth();
        ~EnemyClass();
};

#endif 
