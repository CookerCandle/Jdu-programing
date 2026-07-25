#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <random>

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


class SubmarineFactory {
public:
    virtual std::shared_ptr <Submarine> create(int row, int col) = 0;

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


class SimpleSubmarineFactory : public SubmarineFactory {
public:
    std::shared_ptr <Submarine> create(int row, int col) override {
        return std::make_shared <SimpleSubmarine>(row, col);
    }
};


class DurableSubmarine : public Submarine {
private:
    int durability;
public:
    DurableSubmarine(int row, int col, int d)
    : Submarine(row, col),
    durability(d)
    { }

    void decreaseDurability() {    
        --durability;
        if(durability <= 0) {
            state = Sunc;
        }
    }

    void updateState(const Move& move) override {
        if(move.getPosition() == this->getPosition()) {
            decreaseDurability();
        }
    }
    
};


class DurableSubmarineFactory : public SubmarineFactory {
private:
    int durability;
public:
    DurableSubmarineFactory(int d)
    : durability(d)
    { }
    
    std::shared_ptr <Submarine> create(int row, int col) override {
        return std::make_shared <DurableSubmarine>(row, col, durability);
    }
};


class Board {
public: 
    enum CellState{Unselected, Selected, Sunc};
private:
    const int rows;
    const int cols;

    std::vector <std::vector <CellState>> cells;
    std::vector <std::shared_ptr <Submarine>> submarines;
    
    Move last_move;
public:
    Board(const int r, const int c)
    : rows(r), cols(c), cells(rows, std::vector <CellState> (cols, Unselected)) { }
    void initialize();

    void setMove(const Move& move);
    void setCellState(int row, int col, CellState state);

    int getRows() const {return rows;}
    int getCols() const {return cols;}
    CellState getCellState(int row, int col) const {return cells[row][col];}
    const std::vector <std::shared_ptr <Submarine>>& getSubmarine() const {return submarines;}
    const Move& getLastmove() const {return last_move;}

    bool isGameOver() const;
    void print() const;
};

void Board::initialize(){
#if 0
    submarines.push_back(std::make_shared <SimpleSubmarine>(4, 5));
    submarines.push_back(std::make_shared <DurableSubmarine>(2, 3, 2));
#endif

    std::vector <std::shared_ptr <SubmarineFactory>> factories;
    factories.push_back(std::make_shared <SimpleSubmarineFactory>());
    factories.push_back(std::make_shared <DurableSubmarineFactory>(2));
    // factories.push_back(std::make_shared <SimpleSubmarineFactory>(3));

    std::random_device seeder;
    std::mt19937 gen(seeder());
    std::uniform_int_distribution <int> row_dist(0, rows - 1);
    std::uniform_int_distribution <int> col_dist(0, cols - 1);
    std::uniform_int_distribution <int> SubmarineFactory_dist(0, factories.size() - 1);
    std::uniform_int_distribution<int> factory_dist(0, factories.size() - 1);

    for(int i = 1; i < 2; ++i) {
        const int row = row_dist(gen);
        const int col = col_dist(gen);

        bool position_occupied = false;
        for (const std::shared_ptr <Submarine>& submarine : submarines) {
            if (submarine->getPosition().row == row && submarine->getPosition().col == col) {
                position_occupied = true;
                break;
            }
        }

        if(position_occupied) {
            --i;
            continue;
        }

        const int factory_index = factory_dist(gen);

        std::shared_ptr <Submarine> new_sub = factories[factory_index]->create(row, col);
        submarines.push_back(new_sub);
    }

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

    for(std::shared_ptr<Submarine> submarine : submarines){
        if(submarine && !submarine->isSunc()) {
            submarine->updateState(move);
            if(submarine->isSunc()) {
                const Position& sub_pos = submarine->getPosition();
                cells[sub_pos.row][sub_pos.col] = Sunc;
                std::cout << "========\n" << "位置 (" << sub_pos.row << ", " << sub_pos.col << ") で" << " 潜水艦を撃沈しました\n" << "========" << std::endl;
            }
        }
    }
}

bool Board::isGameOver() const {
    if (!last_move.isValid()){
        return false;
    }

    if (submarines.empty()) {
        return true;
    }

    for(const std::shared_ptr<Submarine>& submarine: submarines) {
        if (!submarine->isSunc()) {
            return false;
        }
    }


    return true;
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
        int min_distance = 1000000;
        for (const std::shared_ptr<Submarine>& submarine: submarines) {
            if(!submarine->isSunc()) {
                int distance = last_move.getPosition().manhattanDistance(submarine->getPosition());
                if(distance < min_distance) {
                    min_distance = distance;
                }
            }
        }
        if (min_distance == 1000000) {
            std::cout << "すべての潜水艦が撃沈されました" << std::endl;
        }else {
            std::cout << "入力位置からもっとも近い潜水艦までの距離は " << min_distance << std::endl;
            if(min_distance == 0) {
                std::cout << "距離の潜水艦が存在します。耐久値を減少させました。"  << std::endl;
            }
        }
    }
}


class BoardRender {
public:
    virtual void render(const Board& board) = 0;
};


class ConsoleBoardRenderer : public BoardRender {
public:
    void render(const Board& board) override;
};


void ConsoleBoardRenderer::render(const Board& board) {
    board.print();
}


class FancyConsoleBoardRenderer : public BoardRender {
private:
    std::shared_ptr <BoardRender> component;
public:
    FancyConsoleBoardRenderer(std::shared_ptr <BoardRender> other)
    : component(other)
    { }

    void render(const Board& board) override;
};

void FancyConsoleBoardRenderer::render(const Board& board) {
    std::cout << "=============================\n";
    std::cout << "   潜水艦ゲーム\n";
    std::cout << "=============================\n";
    
    component->render(board);

    std::cout << "=============================\n";
    if(board.isGameOver()) {
        std::cout << "ゲームオーバー！すべての潜水艦が撃沈されました" << std::endl;
    } else {
        std::cout << "ゲーム航行中..." << std::endl;
    }
    std::cout << "=============================\n";
    
}


int main() {
    const int rows = DEFAULT_ROWS;
    const int cols = DEFAULT_COLS;

    std::shared_ptr <BoardRender> console_renderer = std::make_shared <ConsoleBoardRenderer>();
    std::shared_ptr <BoardRender> fancy_renderer = std::make_shared <FancyConsoleBoardRenderer>(console_renderer);

    std::shared_ptr <BoardRender> renderer = fancy_renderer;

    ConsoleMoveReader move_reader;

    Board board(rows, cols);
    board.initialize();
    // board.print();
    renderer->render(board);

    while(!board.isGameOver()) {
        Move move = move_reader.read();
        board.setMove(move);
        // board.print();
        renderer->render(board);
    }

    return 0;
}