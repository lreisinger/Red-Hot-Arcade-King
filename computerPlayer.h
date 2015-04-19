#include <string>
#include "player.h"

class ComputerPlayer: public Player {
public:
    ComputerPlayer(std::string s, char kur);
    ~ComputerPlayer();
    void printName() const;
    int chooseColumn() const;
};
