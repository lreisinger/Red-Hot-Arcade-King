// Von Dominik Hofmann & Lukas Reisinger

#include <iostream>
#include "player.h"

Player::Player(std::string s):name(s)  {
}

int Player::chooseColumn() const {
    return -1;
}

void Player::printName() const {
    std::cout << "Diese Ausgabe sollte nicht zu sehen sein!" << std::endl;
}
