//Von Dominik Hofmann & Lukas Reisinger
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "board.h"
#include <string>
#include <iostream>

bool spielZug(Player * p);
void printWinner(Player * p);
bool playerStarts();
Player * createHumanPlayer();
Player * createCpu(bool secondCpu);
Player * changePlayer(bool start, int turn);
bool newRound();

int game() {
    std::string name, buffer;
    Player * playerA;
    Player * playerB;
    int turn, choice;
    bool game, win, start;
    char c;
    do {
        //Spielmodus wählen
        std::cout << "Choose game mode:" << std::endl;
        std::cout << "(1) human player vs human player" << std::endl;
        std::cout << "(2) human player vs computer player" << std::endl;
        std::cout << "(3) human player vs human player" << std::endl;
        std::cout << "Your choice: " << std::endl;
        std::cin >> choice;
        while (choice<1||choice>3) {
            std::cout << "Wrong imput!" << std::endl; << "Your choice: " << std::endl;
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

    } while (newRound());
    return 0;
}
