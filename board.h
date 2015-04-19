//Von Dominik Hofmann & Lukas Reisinger
#include <string>
#include "player.h"

class Board {
public:
    Board(int columns, int lines);
    //~Board();
    int insertColumn() const;
    bool setStone(int column, Player *player);
    bool columnFull(int column);
    void show();
private:
    int columns;
    int lines;
    char** fields;
};
