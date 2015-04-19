//Von Dominik Hofmann & Lukas Reisinger
#include <string>
#include "player.h"

class Board {
public:
    Board(int columns, int lines);
    ~Board();
    bool setStone(int column, Player *player);
    bool columnFull(int column) const;
    bool isColumn(int col) const;
    void show() const;
private:
    int columns;
    int lines;
    char** fields;
    bool isLine(int line) const;
    bool isField(int line, int col) const;
    bool checkWin(int line, int column, Player *player) const;
};
