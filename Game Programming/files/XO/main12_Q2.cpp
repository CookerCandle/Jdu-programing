#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <cstdio>
#include <random>

const int BOARD_SIZE = 3;
const int FIRST_PLAYER = 1;
const int SECOND_PLAYER = -1;
const int EMPTY = 0;


class Board {
private:
    int cells[BOARD_SIZE][BOARD_SIZE];
public:
    void init();
    void print() const;
    int getCell(int row, int col) const {
        return(checkRange(row, col) ? cells[row][col] : EMPTY);
    }
    bool checkRange(int row, int col) const;
    bool checkEmpty(int row, int col) const;
    bool update(int row, int col, int player);
    int checkWinner() const;
};

void Board::init(){
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cells[row][col] = EMPTY;
        }
    }
}

void Board::print() const {
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

bool Board::checkRange(int row, int col) const {
    return (0 <= row && row < BOARD_SIZE && 0 <= col && col < BOARD_SIZE);
}

bool Board::checkEmpty(int row, int col) const {
    if (checkRange(row, col) && cells[row][col] == EMPTY){
        return true;
    }
    return false;
}

bool Board::update(int row, int col, int player){
    if(!checkRange(row, col)){
        std::cout << "行番号と列番号は~" << BOARD_SIZE - 1 << "の整数でなければいけません。" << std::endl;    
        return false;
    }

    if(!checkEmpty(row, col)) {
        std::cout << "そのマスは眠に埋まっています。別のマスを選んでください。" << std::endl;
        return false;
    }

    cells[row][col] = player;
    return true;
};

int Board::checkWinner() const {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        if (cells[row][0] != EMPTY 
            && cells[row][0] == cells[row][1] 
            && cells[row][1] == cells[row][2]) 
        {
            return cells[row][0];
        }
    }

    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (cells[col][0] != EMPTY 
            && cells[col][0] == cells[col][1] 
            && cells[col][1] == cells[col][2]) 
        {
            return cells[col][0];
        }
    }

    if (cells[0][0] != EMPTY
        && cells[0][0] == cells[1][1]
        && cells[1][1] == cells[2][2]) 
    {
        return cells[0][0];
    }

    if (cells[0][2] != EMPTY
        && cells[0][2] == cells[1][1]
        && cells[1][1] == cells[2][0])
    {
        return cells[0][2];
    }


    return EMPTY;
}


class Player {
private:
    std::string name;
    int number;
public:
    Player(const std::string& n, int num)
        : name(n), number(num){}
    const std::string& getName() const {return name;}
    int getNumber() const {return number;}
    int getMark() const {return number == FIRST_PLAYER ? 'X' : 'O';}

    virtual void getDicision(const Board& board, int& row, int& col) = 0;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& n, int num)
        : Player(n, num){}

    void getDicision(const Board& board, int& row, int& col) override;
};

void HumanPlayer::getDicision(const Board& board, int& row, int& col){
    std::string input_str;
    std::cout << "プレイヤ" << getNumber() << "(" << (char)getMark() << ")" << "の番です。\n";
    std::cout << "行番号を入力してください: ";
    if (!std::getline(std::cin, input_str) || 
        sscanf(input_str.c_str(), "%d", &row) != 1){
        std::cout << "不正な入力です。" << std::endl;
        return;
    }

    std::cout << "列番号を入力してください: ";
    if (!std::getline(std::cin, input_str) || 
        sscanf(input_str.c_str(), "%d", &col) != 1){
        std::cout << "不正な入力です。" << std::endl;
        return;
    }
}

class RandomPlayer : public Player {
public:
    RandomPlayer(const std::string& n, int num)
        : Player(n, num){}

    void getDicision(const Board& board, int& row, int& col) override;
    void getDicisionSimple(const Board& board, int& row, int& col);
    void getDicisionEfficient(const Board& board, int& row, int& col);
};

void RandomPlayer::getDicision(const Board& board, int& row, int& col) {
    getDicisionSimple(board, row, col);
    // getDicisionEfficient(board, row, col);
}

void RandomPlayer::getDicisionSimple(const Board& board, int& row, int& col) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<> dst(0, BOARD_SIZE - 1);

    do {
        row = dst(gen);
        col = dst(gen);
    } while (!board.checkEmpty(row, col));
}

void RandomPlayer::getDicisionEfficient(const Board& board, int& row, int& col) {
    std::vector <std::pair <int, int> > empty_cells;
    for(int r =0; r < BOARD_SIZE; ++r) {
        for(int c = 0; c < BOARD_SIZE; ++c) {
            if(board.checkEmpty(r, c)) {
                empty_cells.push_back(std::make_pair(r, c));
            }
        }
    }
    if (!empty_cells.empty()) {
        static std::random_device seeder;
        static std::mt19937 gen(seeder());
        std::uniform_int_distribution<> dst(0, empty_cells.size() - 1);
        int index = dst(gen);
        row = empty_cells[index].first;
        col = empty_cells[index].second;
    } else {
        row = -1;
        col = -1;
    }
}

class MyCPUPlayer : public Player {
public:
    MyCPUPlayer(const std::string& n, int num)
        : Player(n, num){}
    void getDicision(const Board& board, int& row, int& col) override;
};

void MyCPUPlayer::getDicision(const Board& board, int& row, int& col) {
    for(int r = 0; r < BOARD_SIZE; ++r) {
        int count_mine = 0;
        int count_opp = 0;
        for(int c = 0; c < BOARD_SIZE; ++c) {
            int cell_value = board.getCell(r, c);
            if (cell_value == EMPTY) {
                continue;
            } else {
                if (cell_value == getNumber()) {
                    count_mine += 1;
                } else {
                    count_opp += 1;
                }
            }
        }

        if (count_opp == BOARD_SIZE - 1 && count_mine == 0) {
            for(int c = 0; c < BOARD_SIZE; ++c) {
                if (board.checkEmpty(r, c)) {
                    row = r;
                    col = c;
                    return;
                }
            }
        }
    }
}

int main() {
    Board board;

    board.init();
    board.print();

    std::shared_ptr <Player> player1 (new HumanPlayer("Player1", FIRST_PLAYER));
    // std::shared_ptr <Player> player2 (new HumanPlayer("Player2", SECOND_PLAYER));
    std::shared_ptr <Player> player2 (new RandomPlayer("Random2", SECOND_PLAYER));

    std::queue <std::shared_ptr <Player>> players;
    players.push(player1);
    players.push(player2); 
    std::shared_ptr <Player> current_player = players.front();
    players.pop();
    
    for (int turn = 1; turn <= BOARD_SIZE * BOARD_SIZE; ++turn) {
        std::cout << "ターン" << turn << ": プレイヤ" << current_player->getName() << " の番です。" << std::endl;
        int row, col;
        current_player->getDicision(board, row, col);
    
        if (!board.update(row, col, current_player->getNumber())) {
            --turn;
            continue;
        }
        board.print();

        if (board.checkWinner() != EMPTY) {
            std::cout << "プレイヤ" << current_player->getName() << "の勝ちです!<<" << std::endl;
            break;
        }

        players.push(current_player);
        current_player = players.front();
        players.pop();
    }

    return 0;
}