//Von Dominik Hofmann & Lukas Reisinger
#include <string>
#include "player.h"

class HumanPlayer: public Player {
public:
    HumanPlayer(std::string s, char kur);
    ~HumanPlayer();
    void printName() const;
    int chooseColumn() const;
};
