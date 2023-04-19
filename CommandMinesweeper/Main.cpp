#include <iostream>
#include <string>
#include "Minesweeper.hpp"

int main(int argc, char* argv[]) {
    
    std::cout << "Welcome to Command Line Minesweeper" << std::endl;
    std::cout << "Select Difficulty: Beginner, Intermediate, Expert" << std::endl;
    std::cout << "Press q to Quit" << std::endl;
    std::string difficulty;
    std::cin >> difficulty;
    while (difficulty != "q") {
       Minesweeper game(difficulty);
        game.print_board();
        game.place_mines();
        while (!game.game_win()) {
            int x, y;
            std::cout << "Enter x coordinate: ";
            std::cin >> x;
            if (std::cin.fail()) {
                break;
            }
            std::cout << "Enter y coordinate: ";
            std::cin >> y;
            if (std::cin.fail()) {
                break;
            }
            try {
                game.make_move(x, y);
            } catch (std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                break;
            }
            game.print_board();
        }
        if (game.game_win()) {
            std::cout << "You Win!" << std::endl;
        }
        // std::cout << "Select Difficulty: Beginner, Intermediate, Expert" << std::endl;
        // std::cout << "Press q to Quit" << std::endl;
        // std::cin >> difficulty;
    }
    // while (std::find(valid_difficulties.begin(), valid_difficulties.end(), difficulty) == valid_difficulties.end()) {
    //     std::cout << "Invalid difficulty" << std::endl;
    //     std::cout << "Please Enter One Of: Beginner, Intermediate, Expert" << std::endl;
    //     std::cout << "[ESC to Quit]" << std::endl
    //     std::cin >> difficulty;
    // }
    // std::cout << "Usage:" << std::endl;
    // print_usage();

}

// void print_usage() {
//     std::cout << "Usage: ./minesweeper [difficulty]" << std::endl;
// }