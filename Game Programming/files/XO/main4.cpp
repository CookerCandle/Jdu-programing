#include <iostream>

const int BOARD_SIZE = 3;
const int FIRST_PLAYER = 1;
const int SECOND_PLAYER = -1;
const int EMPTY = 0;


void board_init(int cells[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cells[row][col] = EMPTY;
        }
    }
}


void board_print(const int cells[BOARD_SIZE][BOARD_SIZE]) {
    std::cout << " ";
        for (int col = 0; col < BOARD_SIZE; ++col) {
            std::cout << "  " << col;
        }
        std::cout << '\n';

        for (int row = 0; row < BOARD_SIZE; ++row) {
            std::cout << row << " ";
            for (int col = 0; col < BOARD_SIZE; ++col) {
                if (cells[row][col] == FIRST_PLAYER) {
                    std::cout << "[X]";
                } else if (cells[row][col] == SECOND_PLAYER) {
                    std::cout << "[O]";
                } else {
                    std::cout << "[ ]";
                }
            }
            std::cout << '\n';
        }
        std::cout << std::flush;
}


int main() {

    int cells[BOARD_SIZE][BOARD_SIZE];

    board_init(cells);

    cells[0][0] = FIRST_PLAYER;  // X
    cells[1][1] = SECOND_PLAYER; // O

    board_print(cells);

    return 0;
}