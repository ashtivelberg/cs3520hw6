#include "MineCell.hpp"

MineCell::MineCell(int x, int y): c_is_mine(false), c_is_revealed(false), c_is_flagged(false), nearCount(0), c_x(x), c_y(y) {}

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
    c_is_revealed = true;
}

void MineCell::set_flagged() {
    c_is_flagged = true;
}

