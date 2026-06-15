#include <iostream>
#include <string>

int main() {
    std::string greeting = "Hello";
    std::string target = "World";

    std::string message; // Hello World
    message = greeting + ", " + target + "!";

    std::cout << message << std::endl;

    // moji
    std::string full_name;
    std::cout << "名前を入力してください(スペース可 :";

    // std::cin >> full_name;
    std::getline(std::cin, full_name);

    //
    std::cout << "名前文字列の長さ" << full_name.size() << std::endl;
    std::cout << "名前文字列の長さ" << full_name.length() << std::endl;

    //
    std::cout << "名前の一文字目" << full_name[0] << std::endl;
    std::cout << "名前の一文字目" << full_name.at(0) << std::endl;

    //
    std::string password = "apple";
    std::string user_input;
    std::cin >> user_input;

    //if (strcmp(user_input.c_str(), password.c_str()) == 0)
    if (user_input == password) {
        
    } else if (user_input < password) {
        // user_input = "banana";

    } 

    return 0;
}
