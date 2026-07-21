#include <iostream>

const int DEFAULT_ROWS = 9;
const int DEFAULT_COLS = 9;

class Position {
public:
    int row;
    int col;

    Position()
    : row(-1), col(-1) { }

    Position(int r, int c)
    : row(r), col(c) { }

    Position& assign(int r, int c) {
        row = r;
        col = c;
        return *this;
    }   
    int manhattanDistance(const Position& other) const {
        return std::abs(this->row - other.row) + std::abs(this->col - other.col);
    }
};

class Move {
private:
    Position pos;
    bool valid;
public:
    Move()
    : pos(-1, -1), valid(false) { }

    Move(int r, int c, bool v) 
    : pos(r, c), valid(v) { }

    bool isValid() const {return valid;}
    const Position& getPosition() const {return pos;}
    int getRow() const {return pos.row;}
    int getCol() const {return pos. col;}
};


class ConsoleMoveReader {
public: 
    Move read();
};

Move ConsoleMoveReader::read() {
    int read_row = -1;
    char read_col_char = '\0';
    std::cout << "階軸の値を入力してください [1-" << DEFAULT_ROWS << "]>";
    std::cin >> read_row;
    std::cout << "階軸の値を入力してください [A-" << static_cast <char> ('A' + DEFAULT_COLS - 1) << "]>";
    std::cin >> read_col_char;

    int row = read_row -1;
    int col = read_col_char - 'A';

    if (0 <= row && row < DEFAULT_ROWS && 0 <= col && col < DEFAULT_COLS) {
        return Move(row, col, true);
    }
    return Move();
}


class Board {
private:
    const int rows;
    const int cols;

    Position submarine_pos;
    
    Move last_move;
public:
    Board(const int r, const int c)
    : rows(r), cols(c), submarine_pos(-1, -1) { 
        submarine_pos.assign(4, 5);
        // submarine_row = 4;
        // submarine_col = 5;
    }

    void setMove(const Move& move);

    void print() const;
};

void Board::setMove(const Move& move) {
    if (!move.isValid()) {
        std::cout << "無効な入力です" << std::endl;
        return;
    }

    std::cout << "入力した位置: (" << move.getRow() + 1 << ", " << static_cast <char> ('A' + move.getCol()) << std::endl;
    last_move = move;
}

void Board::print() const {
    std::cout << "  ";
    for (int col = 0; col < cols; ++col) {
        std::cout << static_cast <char> ('A' + col) << " ";
    }
    std::cout << std::endl;

    for (int row = 0; row < rows; ++row) {
        std::cout << row + 1 << "|";
        for (int col = 0; col < cols; ++col) {
            if (row == last_move.getRow() && col == last_move.getCol()){
                if(row == submarine_pos.row && col == submarine_pos.col) {
                    std::cout << "X|";
                } else {
                    std::cout << "*|";
                }
            } else {
                std::cout << " |";
            }
        }
        std::cout << std::endl;
    }

    if(last_move.isValid()){
        // int distance = std::abs(last_move.getRow() - submarine_pos.row) + std::abs(last_move.getCol() - submarine_pos.col);
        int distance = last_move.getPosition().manhattanDistance(submarine_pos);
        if (distance == 0) {
            std::cout << "潜水艦の位置は " << submarine_pos.row + 1 << " " << static_cast <char> ('A' + submarine_pos.col) << std::endl;
            std::cout << "撃沈しました" << std::endl;
        } else {
            std::cout << "入力位置から潜水艦までの距離は " << distance << std::endl;
        }
    }
}

int main() {
    const int rows = DEFAULT_ROWS;
    const int cols = DEFAULT_COLS;

    ConsoleMoveReader move_reader;

    Board board(rows, cols);
    board.print();

    Move move = move_reader.read();
    board.setMove(move);
    board.print();

    return 0;
}