#include "Gargoyle.h"

Gargoyle::Gargoyle()
    :EnemyClass(), loot(0), level(0) {}

Gargoyle::Gargoyle(int damage, int lifeForce, int souls, int room)
    :EnemyClass(damage, lifeForce), loot(souls), level(room) {}

bool Gargoyle::attackFunction(int* lifeForce, int* playerLoot) {
    cout << "\n\nGargoyles are sharp creatures, don't led them trick you, we need to reach the upper levels if\nwe want to escape the Mansion.\n\n";
    if (rearange()) {
        *lifeForce -= 100;
        return false;
    }
    else {
        cout << "Good, let's move to next level\n";
        *playerLoot += loot;
        return true;
    }
}

bool Gargoyle::rearange() {
    bool find = true;
    int hold;
    int combination1 = 53214, combination2 = 312645, combination3 = 27891036145;
    cout << "Find the combination of words to the Gargoyle code, but be careful, one mistake can be lethal. \n(place the words in order in a numerical way)\nExample: 1234567\n";

    switch (level) {
    case 1:
        cout << " 1. hide \n 2. to \n 3. love \n 4. coins \n 5. Ghost\n\n";
        cout << "Make your combination: ";
        cin >> hold;
        if (hold == combination1) {
            find = false;
        }
        break;
    case 2:
        cout << " 1. have \n 2. sharp \n 3. Werewolf \n 4. be \n 5. careful! \n 6. claws\n\n";
        cout << "Make your combination: ";
        cin >> hold;
        if (hold == combination2) {
            find = false;
        }
        break;
    case 3:
        cout << " 1. visiting \n 2. Gargoyles \n 3. you \n 4. the \n 5. mansion \n 6. for \n 7. are \n 8. lonely \n 9. creatures \n 10. thank\n\n";
        cout << "Make your combination: ";
        
        cin >> hold;
        if (hold == combination3) {
            find = false;
        }
        break;
    default:
        break;

    cout << "\n\n";
    }

    return find;
}



Gargoyle::~Gargoyle() {
    
}

