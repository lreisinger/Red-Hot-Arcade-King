//Von Dominik Hofmann & Lukas Reisinger
#include <string>
#include <iostream>

class Player {
public:
    Player(std::string s, char kur);
    virtual ~Player(){std::cout << "Player geloescht!" << std::endl;}
    virtual void printName() const;
    virtual int chooseColumn() const = 0;
protected:
    std::string name;
    char kuerzel;
};
