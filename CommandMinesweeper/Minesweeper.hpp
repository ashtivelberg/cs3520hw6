// Header file for Minesweeper.cpp

#ifndef MINESWEEPER_HPP
#define MINESWEEPER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "MineCell.hpp"

class Minesweeper final {
public:
    Minesweeper();
    Minesweeper(std::string difficulty);
    void print_board();
    void place_mines();
    bool is_valid_move(int x, int y);
    void update_neighbors(int x, int y);
    bool game_win();
    void make_move(int x, int y);
    bool bfs_helper(int x, int y);
    bool bfs();
private:
    int m_rows; // height
    int m_cols; // width
    int m_mines; //numMines
    std::vector<std::vector<MineCell> > m_board; // tiles
};

#endif