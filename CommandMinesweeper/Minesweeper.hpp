// Header file for Minesweeper.cpp

#ifndef MINESWEEPER_HPP
#define MINESWEEPER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "MineCell.hpp"

std::vector<std::string> valid_difficulties = {"Beginner", "Intermediate", "Expert"};
std::map<std::string, std::vector<int>> difficulty_map = {
    {"Beginner", {9, 9, 10}},
    {"Intermediate", {16, 16, 40}},
    {"Expert", {16, 30, 99}}
};

class Minesweeper final {
public:
    Minesweeper();
    Minesweeper(std::string difficulty);
    void print_board();
    void place_mines();
    bool is_valid_move(int x, int y);
    void Minesweeper::update_neighbors(int x, int y);
    bool game_win();
    void make_move(int x, int y);
    bool bfs_helper(int x, int y);
    bool bfs();
private:
    int m_rows; // height
    int m_cols; // width
    int m_mines; //numMines
    std::vector<std::vector<MineCell>> m_board; // tiles
};

#endif