// Von Dominik Hofmann & Lukas Reisinger

#include <iostream>
#include "player.h"

Player::Player(std::string s, char kur):kuerzel(kur), name(s)  {
}

void Player::printName() const {
    std::cout << "Diese Ausgabe sollte nicht zu sehen sein!" << std::endl;
}
