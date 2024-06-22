#include "Werewolf.h"

Werewolf::Werewolf()
    :EnemyClass(), loot(0), clawSize(6) {}

Werewolf::Werewolf(int damage, int lifeForce, int money, int size)
    :EnemyClass(damage, lifeForce), loot(money), clawSize(size) {}

bool Werewolf::attackFunction(int* lifeLocation, int* playerloot) {
    char attackword;
    cout << "Careful, it appears that we have encounter a Werewolf. Pay attention to their claws, the bigger they are the more damage they inflict.";
    cout << " ";
    cout << "You have to attack, there is no defending yourself against a Werewolf!\n";
    system("pause");

    while (healthBar > 0) {
        //cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";
        
        cout << "\nQuick! use Silver to attack by typing [W], it would reduce the size of its claws and the power of its attack.\n\n";
        cin >> attackword;
        if (toupper(attackword) == 'W') {
            destroyClaw(randomDamage());
            damageW();
            cout << "Good, it took damage: \nHealth: " << getHealth() << " \nWerewolf Attack Power: " << getAttackPower() << endl << "Prepare for attack!\n\n";
        }
        else {
            //did not attack
            cout << "It appears you missed! Prepare for attack.\n\n";
        }
        // reduce player health. and place everything in a while loop
        *lifeLocation -= getAttackPower();


        if (*lifeLocation <= 0) {
            return false;
        }

        if (getHealth() == 0) {
            cout << "The Werewold release some Coins! +" << loot << "\n\n";
            *playerloot += loot;
            return true;
        }else { 
            cout << "Stand up! You need to attack again. \n Life Force: " << *lifeLocation << endl;
            cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";
            
        }


        
    }
}

int Werewolf::getloot() { return loot; }

//get a random number for less- or it can be a game if time. 
void Werewolf::destroyClaw(int less) {
    if (clawSize > less) {
        clawSize -= less;
        setAttackPower(clawSize);
    }
    else { clawSize = 1; }
}

void Werewolf::damageW() {
    healthBar -= clawSize;
}

int Werewolf::randomDamage() {
    return (rand() % 6);
}

Werewolf::~Werewolf() {}
   