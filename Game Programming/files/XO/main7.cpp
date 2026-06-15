#include <iostream>
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

bool Board::update(int row, int col, int player){
    if(!checkRange(row, col)){
        std::cout << "行番号と列番号は~" << BOARD_SIZE - 1 << "の整数でなければいけません。" << std::endl;    
        return false;
    }

    cells[row][col] = player;
    return true;
};


int main() {
    Board board;

    board.init();
    board.print();

    int current_player = FIRST_PLAYER;

    int row, col;
    std::string input_str;
    std::cout << "プレイヤ" 
              << current_player << (current_player == FIRST_PLAYER ?  "O" : "X")
              << "の番です。";

    std::cout << "行番号を入力してください: ";
    if (!std::getline(std::cin, input_str) || 
        sscanf(input_str.c_str(), "%d", &row) != 1){
        std::cout << "不正な入力です。" << std::endl;
        return 1;
    }

    std::cout << "列番号を入力してください: ";
    if (!std::getline(std::cin, input_str) || 
        sscanf(input_str.c_str(), "%d", &col) != 1){
        std::cout << "不正な入力です。" << std::endl;
        return 1;
    }

    board.update(row, col, current_player);

    board.print();

    return 0;
}