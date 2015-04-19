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
    bool isColumn(int col);
    void show();
private:
    int columns;
    int lines;
    char** fields;
    bool isLine(int line);
    bool isField(int line, int col);
    bool checkWin(int line, int column, Player *player);
};
