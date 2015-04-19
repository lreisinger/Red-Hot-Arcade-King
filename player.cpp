// Von Dominik Hofmann & Lukas Reisinger

#include <iostream>
#include "player.h"

Player::Player(std::string s, char kur):name(s),kuerzel(kur)  {
}

virtual Player::~Player() {
    std::cout << "Player geloescht!" << oestd::endl;
}

void Player::printName() const {
    std::cout << "Diese Ausgabe sollte nicht zu sehen sein!" << std::endl;
}
