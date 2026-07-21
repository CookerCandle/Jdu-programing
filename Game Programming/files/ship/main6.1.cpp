#include <iostream>
#include <vector>
#include <cmath>

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

    bool equals(const Position& other) const {
        return this->row == other.row && this->col == other.col;
    }
};

bool operator==(const Position& lhs, cols Position& rhs) {
    return lhs.equals(rhs);
}

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
public: 
    enum CellState{Unselected, Selected, Sunc};
private:
    const int rows;
    const int cols;

    std::vector <std::vector <CellState>> cells;
    Position submarine_pos;
    
    Move last_move;
public:
    Board(const int r, const int c)
    : rows(r), cols(c), cells(rows, std::vector <CellState> (cols, Unselected)), submarine_pos(-1, -1) { 
        submarine_pos.assign(4, 5);
        // submarine_row = 4;
        // submarine_col = 5;
    }

    void setMove(const Move& move);
    void setCellState(int row, int col, CellState state);

    bool isGameOver() const;
    void print() const;
};

void Board::setCellState(int row, int col, CellState state) {
    if(0 <= row &&  row < rows && 0 <= col && col < cols) {
        cells[row][col] = state;
    }
}

void Board::setMove(const Move& move) {
    if (!move.isValid()) {
        std::cout << "無効な入力です" << std::endl;
        return;
    }

    std::cout << "入力した位置: (" << move.getRow() + 1 << ", " << static_cast <char> ('A' + move.getCol()) << std::endl;
    last_move = move;

    cells[move.getRow()][move.getCol()] = Selected;
    // if(move.getPosition().row == submarine_pos.row && move.getPosition().col == submarine_pos.col) {
    //     cells[move.getRow()][move.getCol()] = Sunc;
    // }

    // if(move.getPosition().equals(submarine_pos)) {
    if(move.getPosition().equals == submarine_pos) {
        cells[move.getRow()][move.getCol()] = Sunc;
    }
}

bool Board::isGameOver() const {
    if (!last_move.isValid()){
        return false;
    }

    if (submarine_pos.row < 0 || rows <= submarine_pos.row || submarine_pos.col < 0 || cols <= submarine_pos.col) {
        return false;
    }
    return cells[submarine_pos.row][submarine_pos.col] == Sunc;
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
            if(cells[row][col] == Sunc) {
                std::cout << "X|";
            } else if (cells[row][col] == Selected) {
                std::cout << "*|";
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

    while(!board.isGameOver()) {
        Move move = move_reader.read();
        board.setMove(move);
        board.print();
    }

    return 0;
}