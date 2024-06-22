#include "Ghost.h"
#include <cstdlib>
//#include <ctime>



Ghost::Ghost()
    :EnemyClass(), loot(0) {}

Ghost::Ghost(int damage, int lifeForce, int souls)
    :EnemyClass(damage, lifeForce), loot(souls) {}

bool Ghost::hidingGame() {
    //srand(time(0));
    bool defeat = false;
    int select;
    int const Max_Num = 5;
    int hidingSpace[Max_Num];

    for (int i = 0; i < Max_Num; i++) {
        hidingSpace[i] = 1 + (rand() % 10);
    }
    cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";

    cout << "The Ghost is hiding, quick choose a hiding spot (1-9).\n";
    cin >> select;

    for (int i = 0; i < Max_Num; i++) {
        if (hidingSpace[i] == select) {
            defeat = true;
            break;
        }
    }
    return defeat;
}

bool Ghost::attackFunction(int* lifeLocation, int* playerloot) {
    cout << "It seems like we have encounter a Ghost, Here in the Mansion Ghost are experts at hiding.\nThey choose a hiding spot, and attack you from the darkness. Quick choose a spot and scare the Ghost. \nIf not defeated, Ghost have different attack power, be careful.\n\n";
    cout << " ";
    while (!hidingGame()) {
        cout << "It seems like like the Ghost was hiding in a different spot.\n";
        *lifeLocation -= randomDamage();
        cout << *lifeLocation << " Remaining health.\n";
        
        //if ghost killed the player then return 0 for the game to end.
        if (*lifeLocation <= 0) {
            return false;
        }
    }
    cout << "Good, you scared the ghost away!\n\n";
    cout << "The Ghost have realease some Coins! +" << loot << "\n";
    *playerloot += loot;
    return true;
}

int Ghost::getloot() { return loot; }

int Ghost::randomDamage() {
    //srand(time(0));
    int D;
    D = rand() % 6;
    return D;
}

Ghost::~Ghost() {
    
}
