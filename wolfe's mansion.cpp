// wolfe's mansion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
//using namespace std;



#include "EnemyClass.h"
#include "Gargoyle.h"
#include "Werewolf.h"
#include "Ghost.h"
#include "Player.h"

int save(Player hold ) {
    ofstream outFS;

    outFS.open("SavingFile.txt");

    if (!outFS.is_open()) {
        cout << "Could not open file SavingFile.txt.\n";
        return 1;
    }

    //writting in file 
    outFS << hold.getName() << endl;
    outFS << hold.getSouls() << endl;
    outFS << hold.getlifeForce() << endl;
    outFS << hold.getRoom() << endl;
    outFS << hold.getGarroom() << endl;

    outFS.close();
    return 0;
}

Player load(Player hold) {
    ifstream inFS;

    cout << "Loading game information\n";

    inFS.open("SavingFile.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file\n";
    }

    string namehold;
    int holdint;

    getline(inFS, namehold);
    hold.setName(namehold);

    inFS >> holdint;
    hold.setSouls(holdint);
    inFS >> holdint;
    hold.setLife(holdint);
    inFS >> holdint;
    hold.setRoom(holdint);
    inFS >> holdint;
    hold.setGarroom(holdint);

    inFS.close();

    return hold;

}

void print(Player hold) {
    cout << "Name: " << hold.getName() << endl;
    cout << "Coins: " << hold.getSouls() << endl;
    cout << "Health: " << hold.getlifeForce() << endl;
    cout << "Room #: " << hold.getRoom() << endl << endl;
}

int main() {
    char decision;
    cout << "--------------------------------\n";
    cout << "   Welcome to Wolfe's Mansion\n";
    cout << "       Wish to Enter? (Y/N)\n";
    cout << "--------------------------------\n";

    Player runner("none", 0);
    string nm;

    cin >> decision;
    if (toupper(decision) == 'Y') {
        cout << "\nLet's Enter!\n";

        //initialize player



        //ask if first time playing 
        cout << "First time playing? Wish to load previous game? (Y/N) \n";
        cin >> decision;
        if (toupper(decision) == 'Y') {
              
            runner = load(runner);
            cout << "\nPlayer info that was loaded: \n\n";
            print(runner);
            
            cout << "Let's continue playing!\n\n";
            cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n";
            //print player and lets continue
        }
        else {
            cout << "User Name: ";
            cin >> nm;
            runner.setName(nm);
            
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "              Welcome to the Mansion " << runner.getName() << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

            //start story if time permits
            //intructions of the house
            cout << "                       --HOST GHOST--\n";
            cout << "Good morning or after noon, time is not clear inside the mansion. \n"
                << runner.getName() << " Isn't? I have not see a traveler enter the mansion in a long time.\n"
                << "But I'am glad you are here. Oh- the doors? I'm afraid you can't leave, the doors are sealed\n"
                << "unless.. You are able to get the necessary coins to escape, if you pay the fee, the lady of\n"
                << "of the house would let you leave, the fee? Don't worry is only **500 COINS**.\n\n";
            cout << "Now, listen carefully if you wish to get out of the Mansion you first need to explore its \n"
                << "rooms, be careful of the Ghost, they love to steal coins, the Werewolfs are extremely violent\n"
                << "don't be distracted, outsmart the Gargoyles, choose the right chests and you would be out of here\n"
                << "in no time. Good luck, and I hppe you don't become the new Ghost... \n\n";
            cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";
        }
        //Main gameplay

        int i, decisionint; 
        int room;
        int x = 0;
        srand(time(0));
        Ghost Casper(5, 10, 20);
        Werewolf wolf(10, 10, 50, 6);
        
        

        do {

            //all polergeist and if statement of stories if posible.
            if (runner.getSouls() > 100 && runner.getGarroom() == 0) {
                cout << "We have reach the end of this section of the Mansion. To escape you first to need answer the \nGargoyle question. \n";

                system("pause");

                Gargoyle stone1(100, 10, 20, 1);

                if (stone1.attackFunction(runner.getpointerlifeForce(), runner.getpointersouls())) {
                    cout << "The Gargoyle has been defeated, lets continue.\n";
                }
                else {
                    cout << "You could not defeat the Gargoyle.\n";
                    cout << "Game over.";
                    return 0;
                }

                cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";
                runner.setGarroom(1);
            }


            if (runner.getSouls() > 250 && runner.getGarroom() == 1) {
                cout << "We have reach the end of this section of the Mansion. To escape you first to need answer the \nGargoyle question. \n";

                system("pause");

                Gargoyle stone3(100, 10, 20, 2);

                if (stone3.attackFunction(runner.getpointerlifeForce(), runner.getpointersouls())) {
                    cout << "The Gargoyle has been defeated, lets continue.\n";

                }
                else {
                    cout << "You could not defeat the Gargoyle.\n";
                    cout << "Game over.";
                    return 0;
                }

                cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";
                runner.setGarroom(2);
            }


            if (runner.getSouls() > 500 && runner.getGarroom() == 2) {
                cout << "We have reach the end of the Mansion. To escape you answer the last Gargoyle question. \n";

                system("pause");

                Gargoyle stone3(100, 10, 20, 3);

                if (!(stone3.attackFunction(runner.getpointerlifeForce(), runner.getpointersouls()))){
                    cout << "The Gargoyle has been defeated\n";
                    cout << "You have been able to escape the Mansion!";
                    return 0;
                }
                else {
                    cout << "You could not defeat the Gargoyle.\n";
                    cout << "Game over.";
                    return 0;
                }

                runner.setGarroom(3);
                cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";

            }

            cout << "\n ~Current Stats~\n";
            print(runner);

            cout << "   ~Menu~\n";
            cout << "1. Continue \n2. Save \n3. Exit\n\n";
            cin >> decisionint;
            switch (decisionint) {
                case 1:
                    cout << "Let's move\n\n";
                    break;
                case 2:
                    cout << "Game has been saved!\n\n";
                    save(runner);
                    break;
                case 3:
                    cout << "Game has ended";
                    return 0;
                    break;
                default:
                    //cout << "Did not select anything! Game would continue.\n\n";
                    break;
              
            }
            


            
            //make the "w""a""d" selector 
            cout << "There're three rooms for you to enter, select a room (W/A/D): \n";
            cin >> decision;
            if (toupper(decision) == 'W') {
                cout << "->You choose to go Foward\n\n";
            }
            else if (toupper(decision) == 'A') {
                cout << "->You choose to go left.\n\n";
            }
            else if (toupper(decision) == 'D') {
                cout << "->You choose to go right.\n\n";
            }
            else {
                cout << "You did not make a selection, choosing at random!\n\n";
            }

            cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";

            //getting random number
            room = 1 + (rand() % 4);
            

            //main game play with the rooms
            switch (room) {
                case 1:
                    cout << "~Ghost Room~\n\n";
                    
                    if (Casper.attackFunction(runner.getpointerlifeForce(), runner.getpointersouls()))
                    {
                        cout << "Let's continue\n\n";
                    }
                    else {
                        cout << runner.getName() << "'s Health is below zero,\n";
                        cout << "Game has ended\n";
                        return 0;
                    }
                    
                    //Ghost room

                    break;
                case 2:
                    //Werewolf room 
                    cout << "~Werewolf Room~\n\n";
                    wolf.setHealth(10);
                    
                    if (wolf.attackFunction(runner.getpointerlifeForce(), runner.getpointersouls())) {
                        cout << "Lets's continue\n\n";

                    }
                    else {
                        cout << runner.getName() << "'s Health is below zero,\n";
                        cout << "Game has ended\n";
                        return 0;
                    }

                    break;
                case 3:
                    //break room
                    cout << "It appears there is not monsters or chest in this room, feel free to rest. \nThere's still along way to go. ~Increase in Health~\n\n ";
                    if (runner.getlifeForce() < 100) {
           
                        int x = ceil(runner.getlifeForce() * 1.25);
                        if (x > 100) {
                            x = 100;
                        }
                        runner.setLife(x);
                    }
                    break;
                case 4:
                    //tresure trial 2 chest
                    cout << "You entered a chest room, Ghost love to save their treasures in chest, but also traps.\n";
                    cout << "wish to choose a chest? select (Y/N) ";

                    cin >> decision;
                    if (toupper(decision) == 'Y'){
                        room = 1 + (rand() % 3);
                        if (room == 1) { cout << "It appears to be nothing inside the chest\n\n"; }
                        else if (room == 2) {
                            cout << "Trap chest, -5 health\n\n";
                            x = runner.getlifeForce() - 5;
                            runner.setLife(x);
                        }
                        else if (room == 3) {
                            cout << "You found treasure +50 coins\n\n";
                            x = runner.getSouls() + 50;
                            runner.setSouls(x);
                        }
                        else
                            cout << "No selection\n\n";
                    }
                    break;
                default:
                    break;
            }
            //break;

            //cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";



            //count the amount of rooms and save them.
            i = runner.getRoom() + 1;
            runner.setRoom(i);


            cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~--~-~~-~-~--~-~-~-~-~-~-~-\n\n";

        } while (true);

    }
    else {
        cout << "It appears you choose not to enter, save travels.";
    }

    cout << "\nGame had ended\n";
    return 0;
}


