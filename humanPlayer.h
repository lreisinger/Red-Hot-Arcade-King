//Von Dominik Hofmann & Lukas Reisinger

class HumanPlayer: public Player {
public:
    HumanPlayer(std::string s);
    ~HumanPlayer();
    void printName() const;
    int chooseColumn() const;
};
