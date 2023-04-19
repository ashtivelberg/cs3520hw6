#include "Minesweeper.hpp"


Minesweeper::Minesweeper(std::string difficulty) {
    if (std::find(valid_difficulties.begin(), valid_difficulties.end(), difficulty) == valid_difficulties.end()) {
        throw std::invalid_argument("Invalid difficulty");
    }
    m_rows = difficulty_map[difficulty][0];
    m_cols = difficulty_map[difficulty][1];
    m_mines = difficulty_map[difficulty][2];
    for (int i = 0; i < m_rows; i++) {
        std::vector<MineCell> row;
        for (int j = 0; j < m_cols; j++) {
            row.push_back(MineCell(i, j));
        }
        m_board.push_back(row);
    }
}

bool Minesweeper::is_valid_move(int x, int y) {
    return (x >= 0 && x < m_rows && y >= 0 && y < m_cols);
}

void Minesweeper::place_mines() {
    int mines_placed = 0;
    while (mines_placed < m_mines) {
        int x = rand() % m_rows;
        int y = rand() % m_cols;
        if (m_board[x][y].is_mine()) {
            mines_placed--;
            continue;
        }
        m_board[x][y].set_mine();
        mines_placed++;
        update_neighbors(x, y);
    }
}

void Minesweeper::update_neighbors(int x, int y) {
    int adjacent_mines = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (is_valid_move(x + i, y + j)) {
                adjacent_mines++;
            }
        }
    }
    m_board[x][y].set_adjacent_mines(adjacent_mines);
}

bool Minesweeper::bfs() {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (m_board[i][j].is_revealed() && m_board[i][j].adjacent_mines() == 0) {
                if (!bfs_helper(i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Minesweeper::bfs_helper(int x, int y) {
    if (m_board[x][y].is_mine()) {
        return false;
    }
    m_board[x][y].set_revealed();
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (is_valid_move(x + i, y + j) && !m_board[x + i][y + j].is_revealed()) {
                bfs_helper(x + i, y + j);
            }
        }
    }
    return true;
}

void Minesweeper::make_move(int x, int y) {
    if (!is_valid_move(x, y)) {
        throw std::invalid_argument("Invalid move");
    }
    if (m_board[x][y].is_mine()) {
        throw std::invalid_argument("Game Over");
    }
    if (m_board[x][y].is_revealed()) {
        return;
    }
    m_board[x][y].set_revealed();
    // if (m_board[x][y].adjacent_mines() == 0) {
    //     bfs();
    // }
    bfs();
}

bool Minesweeper::game_win() {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (!m_board[i][j].is_mine() && !m_board[i][j].is_revealed()) {
                return false;
            }
        }
    }
    return true;
}

void Minesweeper::print_board() {
    std::cout << "  " ;
    for(int j = 0; j < m_board[0].size(); j++) {
        std::cout << j << "_";
    }
    std::cout << std::endl;

    for (int i = 0; i < m_rows; i++) {
        std::cout << i << "|";
        for (int j = 0; j < m_cols; j++) {
            if (m_board[i][j].is_revealed()) {
                if (m_board[i][j].adjacent_mines() == 0) {
                    std::cout << "_|";
                } else {
                    std::cout << m_board[i][j].adjacent_mines() << " | ";
                }
            } else {
                std::cout << "X ";
            }
        }
        std::cout << std::endl;
    }
}

