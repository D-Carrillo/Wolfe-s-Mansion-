#include "Player.h"

Player::Player() : name("none"), room(0), garroom(0) {
    souls = 0;
    lifeForce = 0;
}

Player::Player(string nm, int space) : name(nm), room(space), garroom(0) {
    souls = 0;
    lifeForce = 100;
}
void Player::setName(string nm) { name = nm; }
void Player::setSouls(int money) { souls = money; }
void Player::setRoom(int space) { room = space; }
void Player::setLife(int force) { lifeForce = force; }
string Player::getName() { return name; }
int Player::getSouls() { return souls; }
int Player::getlifeForce() { return lifeForce; }
int Player::getRoom() { return room; }
int* Player::getpointerlifeForce() { return &lifeForce; }
int* Player::getpointersouls() { return &souls; }
void Player::setGarroom(int gar) { garroom = gar; }
int Player::getGarroom() { return garroom; }
Player::~Player() {} 