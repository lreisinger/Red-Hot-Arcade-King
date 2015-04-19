//Von Dominik Hofmann & Lukas Reisinger
#ifndef   FILE_H //player.h wird öfter gebraucht, maßnahme gegen redefinition of class error
#define   FILE_H

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

#endif
