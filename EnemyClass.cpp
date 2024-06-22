#include "EnemyClass.h"

#include <iostream>
//#include <cstdlib>

//using namespace std;

EnemyClass::EnemyClass() {
    healthBar = 0;
    AP = 0;
}

EnemyClass::EnemyClass(int damage, int lifeForce) : AP(damage)
{
    healthBar = lifeForce;
}

void EnemyClass::setAttackPower(int damage) {
    AP = damage;
}

int EnemyClass::getAttackPower() { return AP; }

void EnemyClass::setHealth(int lifeForce) { healthBar = lifeForce; }

int EnemyClass::getHealth() { return healthBar; }

bool EnemyClass::attackFunction(int* lifeLocation, int* loot) {
    cout << "Normal Attack" << endl;
    *lifeLocation -= 5;
    return true;
}

EnemyClass::~EnemyClass()
{
    
}

