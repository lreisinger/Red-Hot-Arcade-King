//Von Dominik Hofmann & Lukas Reisinger
#include "humanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(std::string s, char kur):Player(s,kur){}

HumanPlayer::~HumanPlayer() {
    std::cout << "HumanPlayer deleted!" << std::endl;
}

void HumanPlayer::printName() const {
    std::cout << "Player " << this->name << std::endl;
}

int HumanPlayer::chooseColumn() const {
    int column;
    std::cout << std::endl << "" << this->name << " choose column: ";
    std::cin >> column;
    return column-1; //Umwandeln Spaltennummer auf Index
}
