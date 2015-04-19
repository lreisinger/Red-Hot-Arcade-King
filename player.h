//Von Dominik Hofmann & Lukas Reisinger
#include <string>

class Player {
public:
    Player(std::string s);
    //~Player();
    void printName() const;
    int chooseColumn() const;
private:
    std::string name;
};
