//Von Dominik Hofmann & Lukas Reisinger
#include "humanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(std::string s, char kur):Player(s,kur){}

HumanPlayer::~HumanPlayer() {
    std::cout << "HumanPlayer geloescht!" << std::endl;
}

void HumanPlayer::printName() const {
    std::cout << this->name << std::endl;
}

int HumanPlayer::chooseColumn() const {
    int column;
    std::cout << "Welche Spalte? ";
    std::cin >> column;
    return column-1; //Umwandeln Spaltennummer auf Index
}
