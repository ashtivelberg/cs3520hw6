#include "MineCell.hpp"

MineCell::MineCell(): c_is_mine(false), c_is_revealed(false), c_is_flagged(false), c_adjacent_mines(0) {}

MineCell::MineCell(int x, int y): c_is_mine(false), c_is_revealed(false), c_is_flagged(false), c_adjacent_mines(0), c_x(x), c_y(y) {}

bool MineCell::is_mine() {
    return c_is_mine;
}

bool MineCell::is_revealed() {
    return c_is_revealed;
}

bool MineCell::is_flagged() {
    return c_is_flagged;
}

int MineCell::adjacent_mines() {
    return c_adjacent_mines;
}

void MineCell::set_mine() {
    c_is_mine = true;
}

void MineCell::set_revealed() {
    if (!c_is_flagged && !c_is_revealed) {
        c_is_revealed = true;
    }
}

void MineCell::set_flagged() {
    c_is_flagged = true;
}

void MineCell::set_adjacent_mines(int adjacent_mines) {
    c_adjacent_mines = adjacent_mines;
}

