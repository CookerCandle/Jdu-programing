#include <iostream>

const int DEFAULT_ROWS = 9;
const int DEFAULT_COLS = 9;

class Board {
private:
    const int rows;
    const int cols;
public:
    Board(const int r, const int c)
    : rows(r), cols(c) { }

    void print() const;
};

void Board::print() const {
    std::cout << "  ";
    for (int col = 0; col < cols; ++col) {
        std::cout << static_cast <char> ('A' + col) << " ";
    }
    std::cout << std::endl;

    for (int row = 0; row < rows; ++row) {
        std::cout << row + 1 << "|";
        for (int col = 0; col < cols; ++col) {
            std::cout << " |";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int rows = DEFAULT_ROWS;
    const int cols = DEFAULT_COLS;

    Board board(rows, cols);
    board.print();

    return 0;
}