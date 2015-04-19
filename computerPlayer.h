#include <string>
#include "player.h"

class ComputerPlayer: public Player {
public:
    ComputerPlayer(char kur, int col, bool secondCpu);
    ~ComputerPlayer();
    void printName() const;
    int chooseColumn() const;
private:
    int columns;
};
