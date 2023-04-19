// Header file for Minesweeper.cpp

#ifndef MINESWEEPER_HPP
#define MINESWEEPER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "MineCell.hpp"

/*
    Main Minesweeper board class. Creates and handles all logisitcs. Basically the model/controller in an MVC design pattern.
*/
class Minesweeper final {
public:
    // Constructor for a Game
    Minesweeper(std::string difficulty);
    // Prints a game
    void print_board();
    // Places mines in a game
    void place_mines();
    // Is the cell in bounds
    bool is_valid_move(int x, int y);
    // Recalculates number of mines around each cell as they're places
    void update_neighbors(int x, int y);
    // Have all non-mine cells been revealed?
    bool game_win();
    // "Clicks" on a cell and act accorsing to what the cell is
    void make_move(int x, int y);
    // Helper for spreading to usless cells when clicked
    bool bfs_helper(int x, int y);
    // spreads click across unnumbered, unmined cells
    bool bfs();
private:
    int m_rows; // height
    int m_cols; // width
    int m_mines; // number of mines
    std::vector<std::vector<MineCell> > m_board; // cells
};

#endif