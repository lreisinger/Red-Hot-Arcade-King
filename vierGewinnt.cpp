//Von Dominik Hofmann & Lukas Reisinger
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "board.h"
#include <string>
#include <iostream>
#include <random>

bool spielZug(Board * board, Player * p);
void printWinner(Player * p);
void printDraw();
bool playerAStarts();
Player * createHumanPlayer();
Player * createCpu(bool secondCpu);
Player * changePlayer(bool start, int turn);
bool isDraw(Board * b);
bool newRound();

int game() {
    const int columns=8;
    const int rows=5;
    Board * board=new Board(columns,rows);
    std::string name, buffer;
    Player * playerA;
    Player * playerB;
    Player * activePlayer;
    int turn, choice;
    bool game, win, start;
    char c;
    do {
        //Spielmodus waehlen
        std::cout << "Choose game mode:" << std::endl;
        std::cout << "(1) human player vs human player" << std::endl;
        std::cout << "(2) human player vs computer player" << std::endl;
        std::cout << "(3) human player vs human player" << std::endl;
        std::cout << "Your choice: " << std::endl;
        std::cin >> choice;
        while (choice<1||choice>3) {
            std::cout << "Wrong imput!" << std::endl << "Your choice: " << std::endl;
            std::cin >> choice;
        }
        switch (choice) {
        case 1:
            playerA=createHumanPlayer();
            playerB=createHumanPlayer();
            break;
        case 2:
            playerA=createHumanPlayer();
            playerB=createCpu(false);
            break;
        case 3:
            playerA=createCpu(false);
            playerB=createCpu(true);
            break;
        }
        //Werte setzen
        turn=1;
        game=true;
        win=false;
        bool start=playerAStarts();
        if (start)
            activePlayer=playerA;
        else
            activePlayer=playerB;
        do {
            win=spielZug(board, activePlayer);
            if (win)
                game=false;
            else {
                activePlayer=changePlayer(start, turn);
                turn++;
            }
            if (isDraw(board))
                game=false;
        } while (game);
    } while (newRound());
    return 0;
}

bool spielZug(Board * board, Player * p) {
    int col=p->chooseColumn();
    while (!(board->isColumn(col)) || board->columnFull(col)) {
        col=p->chooseColumn();
    }
    bool b;
    b=board->setStone(col, p);
    return b;
}

void printWinner(Player * p) {
    std::cout << "Game Over!" << std::endl << "The winner is " << p->name << std::endl;
}

void printDraw() {
    std::cout << "Game Over!" << std::endl << "It's a draw!" << std::endl;
}

bool playerAStarts() {
    int random=(rand()%10)+1;
    if (random<=5)
        return true;
    return false;
}

