#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

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

bool operator==(const Position& lhs, const Position& rhs) {
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

class Submarine {
public: 
    enum State {Alive, Sunc};
private:
    Position pos;
protected:
    State state;
public:
    Submarine(int row, int col)
    : pos(row, col), state(Alive) { }

    const Position& getPosition() const {return pos;}
    State getState() const {return state;}
    bool isSunc() const {return state==Sunc;}

    virtual void updateState(const Move& move) = 0;
};

class SimpleSubmarine : public Submarine {
public:
    SimpleSubmarine(int row, int col)
    : Submarine(row, col) { }
    void updateState(const Move& move) override {
        if (move.getPosition() == this->getPosition()) {
            state = Sunc;
        }
    }
};

class Board {
public: 
    enum CellState{Unselected, Selected, Sunc};
private:
    const int rows;
    const int cols;

    std::vector <std::vector <CellState>> cells;
    std::shared_ptr <Submarine> submarine;
    
    Move last_move;
public:
    Board(const int r, const int c)
    : rows(r), cols(c), cells(rows, std::vector <CellState> (cols, Unselected)) { }
    void initialize();

    void setMove(const Move& move);
    void setCellState(int row, int col, CellState state);

    bool isGameOver() const;
    void print() const;
};

void Board::initialize(){
    submarine = std::make_shared <SimpleSubmarine>(4, 5);
}

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

    // if(submarine && move.getPosition() == submarine->getPosition()) {
    //     cells[move.getRow()][move.getCol()] = Sunc;
    // }
    if(submarine && !submarine->isSunc()) {
        submarine->updateState(move);
        if(submarine->isSunc()) {
            const Position& sub_pos = submarine->getPosition();
            cells[sub_pos.row][sub_pos.col] = Sunc;
        }
    }
}

bool Board::isGameOver() const {
    if (!last_move.isValid()){
        return false;
    }

    if (!submarine) {
        return true;
    }

    if (submarine->isSunc()) {
        return true;
    }

    return false;
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

    if(last_move.isValid() && submarine){
        if (submarine->isSunc()) {
            std::cout << "潜水艦の位置は " << submarine->getPosition().row + 1 << " " << static_cast <char> ('A' + submarine->getPosition().col) << std::endl;
            std::cout << "撃沈しました" << std::endl;
        }else {
            int dist = last_move.getPosition().manhattanDistance(submarine->getPosition());
            std::cout << "入力位置から潜水艦までの距離は " << dist << std::endl;
        }
    }
}

int main() {
    const int rows = DEFAULT_ROWS;
    const int cols = DEFAULT_COLS;

    ConsoleMoveReader move_reader;

    Board board(rows, cols);
    board.initialize();
    board.print();

    while(!board.isGameOver()) {
        Move move = move_reader.read();
        board.setMove(move);
        board.print();
    }

    return 0;
}