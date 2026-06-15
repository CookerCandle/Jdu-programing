#include <iostream>

int main() {
    const int BOARD_SIZE = 3;

    // std::cout << "   0  1  2\n";
    std::cout << " ";
    for (int col = 0; col < BOARD_SIZE; ++col) {
        std::cout << "  " << col;
    }
    std::cout << '\n';

    for (int row = 0; row < BOARD_SIZE; ++row) {
        std::cout << row << " ";
        for (int col = 0; col < BOARD_SIZE; ++col) {
            std::cout << "[ ]";
        }
        std::cout << '\n';
    }
    std::cout << std::flush;

    return 0;
}