//Von Dominik Hofmann & Lukas Reisinger
#include <string>

class Player {
public:
    char kuerzel;
    Player(std::string s, char kur);
    virtual ~Player();
    virtual void printName() const;
    virtual int chooseColumn() const = NULL;
protected:
    std::string name;
};
