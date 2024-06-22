#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
    private:
        string name;
        int souls;
        int lifeForce;
        int room;
        int garroom;
    public:
        Player();
        Player(string, int);
        void setName(string);
        void setSouls(int);
        void setRoom(int);
        void setLife(int);
        void setGarroom(int);
        string getName();
        int getSouls();
        int getlifeForce();
        int getRoom();
        int* getpointerlifeForce();
        int* getpointersouls();
        int getGarroom();


        ~Player();
};

#endif 