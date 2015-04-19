#include <iostream>
#include "board.h"
#include <vector>
using std::vector;


Board::Board(int columns, int lines):
    columns(columns),
    lines(lines)
{

    fields = new char*[lines];
    for (int i = 0; i < lines; ++i) {
        fields[i] = new char[columns];

        for (int j=0; j<columns; ++j) {
            fields[i][j] = '.';
        }

    }
}

//Board::~Board()
//{
//    //dtor
//}


bool Board::setStone(int column, Player *player)
{
    if(column < 0 || column >= columns)
    {
        return false;//column out of bounds
    }

    int place = -1;
    while(fields[place+1][columns] == '.')
    {
        place++;
    }

    if(place > -1)//wenn platz vorhanden
    {
        fields[place][columns] = player->kuerzel;
        return true;
    }
    else
    {
        return false;
    }
}

bool Board::columnFull(int column)
{
    if(fields[columns][0] == '.')
    {
        return false;
    }
    return true;
}



void Board::show() {
    std::cout << std::endl;
    for (int y = 0; y < lines; ++y) {
        for (int x=0; x<columns; ++x) {
            std::cout << fields[y][x];
        }

        std::cout << y+1;
        std::cout << std::endl;
    }
    for (int x=0; x<columns; ++x) {
        std::cout << x+1;
    }
    std::cout << std::endl;
}
