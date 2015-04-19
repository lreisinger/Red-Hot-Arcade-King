//Von Dominik Hofmann & Lukas Reisinger
#ifndef   PLAYER_H //player.h wird oefter gebraucht, massnahme gegen redefinition of class error
#define   PLAYER_H

#include <string>
#include <iostream>

class Player {
public:
    std::string name;
    char kuerzel;
    Player(std::string s, char kur);
    virtual ~Player(){std::cout << "Player deleted!" << std::endl;}
    virtual void printName() const;
    virtual int chooseColumn() const = 0;
};

#endif //PLAYER_H
