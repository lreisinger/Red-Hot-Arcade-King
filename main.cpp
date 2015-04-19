#include <iostream>
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "board.h"

void fun(Player * p) {
    p->printName();
}

int main()
{
    //b->show();
    std::string s1, buffer;
    std::cout << "Name: ";
    std::cin >> s1;
    std::cout << "Kuerzel: ";
    std::cin >> buffer;
    HumanPlayer * h=new HumanPlayer(s1,buffer.at(0));
    std::cout << "Kuerzel AI: ";
    std::cin >> buffer;
    ComputerPlayer * cpu = new ComputerPlayer(buffer.at(0),8);
    std::cout << std::endl;
    fun(h);
    fun(cpu);
    //delete h;


    Board *b = new Board(8, 5);
    //if(b->setStone(2, h))
    //    std::cout << "TRUE";
    b->setStone(2, h);
    b->show();
    b->setStone(3, cpu);
    b->show();
    return 0;
}
