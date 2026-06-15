#include <iostream>
#include <string>
#include <cstdio>

int main() {
    // 課題一：入力と正誤判定
    const int answer = 36;

    std::cout << "数当てゲームを始めます。1から100までの数を当ててください。" << std::endl;
    std::cout << "予想した数を入力してください： " << std::flush;

    int input = 0;
    std::string input_str;

    if (!std::getline(std::cin, input_str) || std::sscanf(input_str.c_str(), "%d", &input) != 1) {
        std::cout << "整数値の読み取りに失敗" << std::endl;
        return 1;
    }

    if (input == answer) {
        std::cout << "正解です！" << std::endl;
    } else {
        std::cout << "不正解です。正解は" << answer << "でした。" << std::endl;
    }

    return 0;
}