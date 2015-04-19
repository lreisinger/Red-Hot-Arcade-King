// Von Dominik Hofmann & Lukas Reisinger

#include <iostream>
#include "player.h"

Player::Player(std::string s, char kur):name(s), kuerzel(kur)  {
}

void Player::printName() const {
    std::cout << "Diese Ausgabe sollte nicht zu sehen sein!" << std::endl;
}
