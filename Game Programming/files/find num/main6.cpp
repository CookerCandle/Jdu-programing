#include <iostream>
#include <string>
#include <cstdio>
#include <random>

int main() {
    std::string level;
    int max_number;

    while (true) {
        std::cout << "難易度を入力してください(easy, medium, hard): ";
        std::cin >> level;
        if (level == "easy") {
            max_number = 10;
            break;
        } else if (level == "medium") {
            max_number = 50;
            break;
        } else if (level == "hard") {
            max_number = 100;
            break;
        } else {
            std::cout << "無効な難易度です。" << std::endl;
            return 1;
        }
        std::cout << level << std::endl;
    }

    std::random_device seeder;
    std::mt19937 gen(seeder());
    std::uniform_int_distribution<> dst(1, max_number);

    const int answer = dst(gen);
    std::cout << "正解" << answer << std::endl;

    const int max_attempts = 5;
    int attempts = 0;
    int loop_count = 0;

    while (attempts < max_attempts) {
        ++loop_count;
        if (loop_count > 5) {
            std::cout << "ループ回数が多すぎるため、終了します。" << std::endl;
            break;
        }

        std::cout << "数当てゲームを始めます1から" << max_number
                    << "の数字を当ててください。" << std::endl;
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

        if (attempts == max_attempts) {
            std::cout << "ゲームオーバー!正解は" << answer << "でした。" << std::endl;
        }
    } // while end

    // if (attempts >= max_attempts) {
    //    std::cout << "ゲームオーバー!正解は" << answer << "でした。" << std::endl;
    // }

    return 0;
}
