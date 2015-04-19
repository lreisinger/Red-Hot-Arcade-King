//Von Dominik Hofmann & Lukas Reisinger
#include <string>

class Board {
public:
    Board(std::string s);
    //~Board();
    void printName() const;
    int insertColumn() const;
private:
    int columns;
    int lines;
    char** fields;
};
