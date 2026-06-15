#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <cstdio>

const int BOARD_SIZE = 3;
const int FIRST_PLAYER = 1;
const int SECOND_PLAYER = -1;
const int EMPTY = 0;


class Board {
private:
    int cells[BOARD_SIZE][BOARD_SIZE];
public:
    void init();
    void print();
    bool checkRange(int row, int col);
    bool checkEmpty(int row, int col);
    bool update(int row, int col, int player);
};

void Board::init(){
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cells[row][col] = EMPTY;
        }
    }
}

void Board::print(){
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

bool Board::checkRange(int row, int col){
    return (0 <= row && row < BOARD_SIZE && 0 <= col && col < BOARD_SIZE);
}

bool Board::checkEmpty(int row, int col) {
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


int main() {
    Board board;

    board.init();
    board.print();

    std::shared_ptr <Player> player1 (new HumanPlayer("Player1", FIRST_PLAYER));
    std::shared_ptr <Player> player2 (new HumanPlayer("Player2", SECOND_PLAYER));

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

        players.push(current_player);
        current_player = players.front();
        players.pop();
    }

    return 0;
}