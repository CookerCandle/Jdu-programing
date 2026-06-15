#include <iostream>
#include <string>
#include <cstdio>
#include <random>

std::string selectLevel() {
    std::string level;

    std::cout << "難易度を入力してください(easy, medium, hard): ";
    std::cin >> level;
    if (level == "easy" || level == "medium" || level == "hard") {
        return level;
    } 

    std::cout << "無効な難易度です。" << std::endl;
    return "";  
}

int generateNumber(const std::string& level) {
    int max_number;
    
    if(level == "easy") {
        max_number = 10;
    } else if (level == "medium") {
        max_number = 50;
    } else if (level == "hard") {
        max_number = 100;
    } else {
        return -1;
    }
    
    std::random_device seeder;
    std::mt19937 gen(seeder());
    std::uniform_int_distribution<> dst(1, max_number);

    return dst(gen);

}

int readPlayerInput() {
    int input = 0;

    std::string input_str;
    if (!std::getline(std::cin, input_str) || std::sscanf(input_str.c_str(), "%d", &input) != 1) {
        std::cout << input_str << std::endl;
        std::cout << "不正な入力です。整数を入力してください。" << std::endl;
    }   
    return input;
}

bool checkAnswer(int answer, int input) {
    if (input == answer) {
        std::cout << "正解です！" << std::endl;
        return true;
    } else {
        std::cout << "不正解。正解は入力した数よりも"
                    << (input < answer ? "大きい" : "小さい。")
                    << "です" << std::endl;
        return false;
    }
}

int main() {
    const std::string level = selectLevel();
    if (level.empty()) {
        return -1;
    }

    const int answer = generateNumber(level);
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

        std::cout << "数当てゲームを始めます1から"
                    << (level == "easy" ? 10 : level == "medium" ? 50 : 100)
                    << "の数字を当ててください。" << std::endl;
        std::cout << "予想した数を入力してください： " << std::flush;

        const int input = readPlayerInput();
        std::cout << input << std::endl;
        if (input == -1) {
            continue;
        }

        ++attempts;

        if (checkAnswer(answer, input)) {
            std::cout << attempts << "回目で正解しました。" << std::endl; 
            break;
        } 

        if (attempts == max_attempts) {
            std::cout << "ゲームオーバー!正解は" << answer << "でした。" << std::endl;
        }
    } // while end

    return 0;
}
