//Von Dominik Hofmann & Lukas Reisinger
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "board.h"
#include <string>
#include <iostream>
#include <random>
#include <time.h>

bool spielZug(Board * board, Player * p);
void printWinner(Player * p);
void printDraw();
bool playerAStarts();
Player * createHumanPlayer(char forbiddenSymbol);
Player * createCpu(bool secondCpu, int columns, char forbiddenSymbol);
Player * changePlayer(bool start, int turn, Player * playerA, Player * playerB);
bool isDraw(Board * b, int columns);
bool newRound();

int main() {
    srand(time(NULL)); //seed for random generator
    const int columns=8;
    const int rows=5;
    Board * board;
    Player * playerA;
    Player * playerB;
    Player * activePlayer;
    int turn, choice;
    bool game, win, start;
    do {
        board=new Board(columns, rows);
        //Spielmodus waehlen
        std::cout << "Choose game mode:" << std::endl;
        std::cout << "(1) human player vs human player" << std::endl;
        std::cout << "(2) human player vs computer player" << std::endl;
        std::cout << "(3) computer player vs computer player" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
        while (choice<1||choice>3) {
            std::cout << "Wrong imput!" << std::endl << "Your choice: " << std::endl;
            std::cin >> choice;
        }
        switch (choice) {
        case 1:
            playerA=createHumanPlayer('.');
            playerB=createHumanPlayer(playerA->kuerzel);
            break;
        case 2:
            playerA=createHumanPlayer('.');
            playerB=createCpu(false, columns, playerA->kuerzel);
            break;
        case 3:
            playerA=createCpu(false, columns, '.');
            playerB=createCpu(true, columns, playerA->kuerzel);
            break;
        }
        //Werte setzen
        turn=1;
        game=true;
        win=false;
        start=playerAStarts();
        if (start)
            activePlayer=playerA;
        else
            activePlayer=playerB;
        std::cout << activePlayer->name << " starts!" << std::endl;
        board->show();
        do {
            win=spielZug(board, activePlayer);
            if (win)
                game=false;
            else {
                activePlayer=changePlayer(start, turn, playerA, playerB);
                turn++;
            }
            if (isDraw(board, columns))
                game=false;
        } while (game);
        std::cout << std::endl;
        if (win)
            printWinner(activePlayer);
        else
            printDraw();
    } while (newRound());
    delete playerA;
    delete playerB;
    delete board;
    return 0;
}

bool spielZug(Board * board, Player * p) {
    int col=p->chooseColumn();
    while (!(board->isColumn(col)) || board->columnFull(col)) {
        col=p->chooseColumn();
    }
    bool b;
    b=board->setStone(col, p);
    std::cout << std::endl << p->name << " chooses column " << col+1 << std::endl;
    board->show();
    return b;
}

void printWinner(Player * p) {
    std::cout << "Game Over!" << std::endl << "The winner is " << p->name << std::endl;
}

void printDraw() {
    std::cout << "Game Over!" << std::endl << "It's a draw!" << std::endl;
}

bool playerAStarts() {
    int random=rand() % 10 + 1;
    if (random<=5)
        return true;
    return false;
}

Player * createHumanPlayer(char forbiddenSymbol) {
    std::string name, buffer;
    std::cout << "Name: ";
    std::cin >> name ;
    std::cout << "Symbol for \"" << name << "\": ";
    std::cin >> buffer;
    while (buffer.at(0)== forbiddenSymbol || buffer.at(0)== '.') {
        std::cout << "Forbidden Symbol! Choose another one: ";
        std::cin >> buffer;
    }
    return new HumanPlayer(name, buffer.at(0));
}

Player * createCpu(bool secondCpu, int columns, char forbiddenSymbol) {
    std::string buffer;
    std::cout << "Symbol for Computer";
    if (secondCpu)
        std::cout << " 2: ";
    else
        std:: cout << ": ";
    std::cin >> buffer;
    while (buffer.at(0)== forbiddenSymbol || buffer.at(0)== '.') {
        std::cout << "Forbidden Symbol! Choose another one: ";
        std::cin >> buffer;
    }
    return new ComputerPlayer(buffer.at(0), columns, secondCpu);
}

Player * changePlayer(bool start, int turn, Player * playerA, Player * playerB) {
    int i=0;
    if (start)
        i=1;
    if ((turn%2)==i)
        return playerB;
    return playerA;
}

bool isDraw(Board * b, int columns) {
    for (int i=0; i<columns; i++) {
        if (!b->columnFull(i))
            return false;
    }
    return true;
}

bool newRound() {
    std::string buffer;
    std::cout << std::endl << "Want to play another game? Yes/No: ";
    std::cin >> buffer;
    while (buffer.at(0)!='Y' && buffer.at(0)!='y' && buffer.at(0)!='N' && buffer.at(0)!='n') {
        std::cout << "Wrong imput! Try it again: ";
        std::cin >> buffer;
    }
    if (buffer.at(0)=='Y' || buffer.at(0)=='y')
        return true;
    return false;
}
