//Von Dominik Hofmann & Lukas Reisinger
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "board.h"
#include <string>
#include <iostream>

bool spielZug(Board * board, Player * p);
void printWinner(Player * p);
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
    return board->setStone(col, p);
}
