// Header file for MineCell.cpp

#ifndef MINECELL_HPP
#define MINECELL_HPP

#include <iostream>

class MineCell final {
public:

    MineCell();
    MineCell(int x, int y);
    bool is_mine();
    bool is_revealed();
    bool is_flagged();
    int adjacent_mines(); // noOfAdjacentMines
    void set_mine(); //setMine
    void set_revealed(); // reveal
    void set_flagged(); // toggleFlag
    void set_adjacent_mines(int adjacent_mines); // markAdjacentMines

private:
    int c_x, c_y; //position
    bool c_is_mine; //state
    bool c_is_revealed; //state
    bool c_is_flagged; //state
    int c_adjacent_mines; 

};

#endif