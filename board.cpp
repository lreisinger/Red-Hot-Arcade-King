//Von Dominik Hofmann & Lukas Reisinger
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
    while(place<(lines-1) && fields[place+1][column] == '.' )
    {
        place++;
    }

    if(place > -1)//wenn platz vorhanden
    {
        fields[place][column] = player->kuerzel;
        return true;
    }
    else
    {
        std::cout << "-1";
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


bool Board::checkWin(int line, int column, Player *player)
{
    if(isField(column, line))
    {
        return false;
    }

    int tmp_line = line;
    int tmp_column = column;
    int counter = 1;

    ///HORIZONTAL:

    while(isColumn(tmp_column+1) && fields[tmp_line][tmp_column+1] == player->kuerzel)//horizontal nach platz
    {
        tmp_column++;
        counter++;
    }

    tmp_column=column;

    while(isColumn(tmp_column-1) && fields[tmp_line][tmp_column-1] == player->kuerzel)//horizontal vor platz
    {
        tmp_column--
        counter++;
    }

    tmp_column=column;

    if(counter = 4)
        return true;

    counter = 1;//reset counter


    ///VERTICAL:

    while(isLine(tmp_line+1) && fields[tmp_line+1][tmp_column] == player->kuerzel)//vertikal unter platz
    {
        tmp_line++;
        counter++;
    }

    tmp_line=line;

    while(isColumn(tmp_line-1) && fields[tmp_line+1][tmp_column] == player->kuerzel)//vertikal ueber platz
    {
        tmp_line--
        counter++;
    }

    tmp_line=line;

    if(counter = 4)
        return true;

    counter = 1;//reset counter


    ///Schaeg: links unten -> rechts oben
    while(isField(tmp_line-1, tmp_column+1) && fields[tmp_line-1][tmp_column+1] == player->kuerzel)//vertikal unter platz
    {
        tmp_line--;
        tmp_column++;
        counter++;
    }

    tmp_line=line;
    tmp_column=column;

    while(isField(tmp_line+1, tmp_column-1) && fields[tmp_line+1][tmp_column-1] == player->kuerzel)//vertikal unter platz
    {
        tmp_line++;
        tmp_column--;
        counter++;
    }

    if(counter = 4)
        return true;

    counter = 1;//reset counter


    ///Schaeg: links oben -> rechts unten
    while(isField(tmp_line+1, tmp_column+1) && fields[tmp_line+1][tmp_column+1] == player->kuerzel)//vertikal unter platz
    {
        tmp_line++;
        tmp_column++;
        counter++;
    }

    tmp_line=line;
    tmp_column=column;

    while(isField(tmp_line-1, tmp_column-1) && fields[tmp_line-1][tmp_column-1] == player->kuerzel)//vertikal unter platz
    {
        tmp_line--;
        tmp_column--;
        counter++;
    }

    if(counter = 4)
        return true;

    //counter = 1;//reset counter
    return false;
}


bool Board::isColumn(int col)
{
    if(col < columns && col >= 0)
        return true;
    return false;
}

bool Board::isLine(int line)
{
    if(line < lines && line >= 0)
        return true;
    return false;
}

bool Board::isField(int line, int col)
{
    if(isLine(line) && isColumn(col))
        return true;
    return false;
}
