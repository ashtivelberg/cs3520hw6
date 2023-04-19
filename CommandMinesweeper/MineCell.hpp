// Header file for MineCell.cpp

#ifndef MINECELL_HPP
#define MINECELL_HPP
/*
    Class for a single MineCell. Handles logic for flagging, knowing how many mines surround it, or if it's useless and empty.
    The flagging is unfortunately unsupported as of now (due to time constraint) but would ideally be able to flag cells.
*/
class MineCell final {
public:
    // Constructor for a Mine
    MineCell(int x, int y);
    // Is it currently a mine
    bool is_mine();
    // has this cell been revealed
    bool is_revealed();
    bool is_flagged(); // unsupported unfortunately 
    // adjacant mine count
    int adjacent_mines(); 
    // makes this cell a mine
    void set_mine();
    // reveals this cell
    void set_revealed(); 
    void set_flagged(); // unsupported unfortunately 
    // count of nearby mines
    int nearCount;
private:
    int c_x, c_y;
    bool c_is_mine;
    bool c_is_revealed; 
    bool c_is_flagged; 
    int c_adjacent_mines; 
};

#endif