#include "Board.h"
#include <vector>"
using std::vector;

#define HEIGHT1

Board::Board(int columns, int lines):
    columns(columns),
    lines(lines)
{

    fields = new char*[height];
    for (int i = 0; i < height; ++i) {
        fields[i] = new char[width];

        for (int j=0; j<width; ++j) {
            fields[i][j] = ".";
        }

    }
    for (int i = 0; i < height; ++i) {
        for (int j=0; j<width; ++j) {
            fields(j,i,0);
        }
    }
}

Board::~Board()
{
    //dtor
}


bool setStone(int column, Player *player)
{
    int place = -1;
    while(fields[columns][place+1] == ".")
    {
        place++;
    }

    if(place > -1)
    {
        fields[columns][place] = player->
        return true;
    }
    else
    {
        return false;
    }
}

bool columnFull(int column)
{
    if(fields[columns][0] == ".")
    {
        return false;
    }
    return true;
}



void ASCIIImage::show() {
    std::cout << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x=0; x<width; ++x) {
            std::cout << imgArray[y][x];
        }
        std::cout << std::endl;
    }
}
