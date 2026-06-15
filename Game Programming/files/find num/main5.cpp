#include <iostream>
#include <string>
#include <cstdio>
#include <random>

int main() {
    std::random_device seeder;
    std::mt19937 gen(seeder());
    std::uniform_int_distribution<> dst(1, 100);

    const int answer = dst(gen);
    std::cout << "正解" << answer << std::endl;

    const int max_attempts = 5;
    int attempts = 0;
    int loop_count = 0;

    while (attempts < max_attempts) {
        ++loop_count;
        if (loop_count > 100) {
            std::cout << "ループ回数が多すぎるため、終了します。" << std::endl;
            break;
        }

        std::cout << "数当てゲームを始めます1から100の数字を当ててください。" << std::endl;
        std::cout << "予想した数を入力してください： " << std::flush;

        int input = 0;

        std::string input_str;
        if (!std::getline(std::cin, input_str) || std::sscanf(input_str.c_str(), "%d", &input) != 1) {
            std::cout << input_str << std::endl;
            std::cout << "不正な入力です。整数を入力してください。" << std::endl;
            continue;
        }

        std::cout << input << std::endl;
        ++attempts;

        if (input == answer) {
            std::cout << "正解です！" 
                        << attempts << " 回目で正解しました。"
                        << std::endl;
            break;
        } else {
            std::cout << "不正解。正解は入力した数よりも"
                        << (input < answer ? "大きい" : "小さい。")
                        << "です" << std::endl;
        }
    }

    return 0;
}
