#include <iostream>

int main() {
    const int BOARD_SIZE = 3;

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            std::cout << "[ ]";
        }
        std::cout << '\n';
    }
    std::cout << std::flush;

    return 0;
}