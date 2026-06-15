#include <iostream>
#include <string>
#include <cstdio>

const int BOARD_SIZE = 3;
const int FIRST_PLAYER = 1;
const int SECOND_PLAYER = -1;
const int EMPTY = 0;


void board_init(int cells[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cells[row][col] = EMPTY;
        }
    }
}


void board_print(const int cells[BOARD_SIZE][BOARD_SIZE]) {
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


int main() {

    int cells[BOARD_SIZE][BOARD_SIZE];

    board_init(cells);

    board_print(cells);

    int current_player = FIRST_PLAYER;

    int row, col;
    std::string input_str;
    std::cout << "プレイヤ" 
              << current_player << (current_player == FIRST_PLAYER ?  "O" : "X")
              << "の番です。";

    std::cout << "行番号を入力してください: ";
    if (!std::getline(std::cin, input_str) || 
        sscanf(input_str.c_str(), "%d", &row) != 1 ||
        row < 0 || BOARD_SIZE <= row){
        std::cout << "不正な入力です。行番号は0~" << BOARD_SIZE - 1 << "の整数で入力してください。" << std::endl;
        return 1;
    }

    std::cout << "列番号を入力してください: ";
    if (!std::getline(std::cin, input_str) || 
        sscanf(input_str.c_str(), "%d", &col) != 1 ||
        col < 0 || BOARD_SIZE <= col){
        std::cout << "不正な入力です。列番号は0~" << BOARD_SIZE - 1 << "の整数で入力してください。" << std::endl;
        return 1;
    }

    cells[row][col] = current_player;

    board_print(cells);

    return 0;
}