//Von Dominik Hofmann & Lukas Reisinger
#ifndef   PLAYER_H //player.h wird oefter gebraucht, massnahme gegen redefinition of class error
#define   PLAYER_H

#include <string>
#include <iostream>

class Player {
public:
    char kuerzel;
    Player(std::string s, char kur);
    virtual ~Player(){std::cout << "Player geloescht!" << std::endl;}
    virtual void printName() const;
    virtual int chooseColumn() const = 0;
protected:
    std::string name;
};

#endif //PLAYER_H
