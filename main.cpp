#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string data, answer = "yes";
    std::ofstream file;
    std::cout << "Enter the data: " << std::endl;
    std::string meaning[4]{"Name ", "Surname ", "Date ", "Sum "};
    file.open("P:\\Statement.txt", std::ios::app);
    file << "\t\tMeaning" << "\n";
    while (answer == "yes") {
        for (int i = 0; i < 4; i++) {
            std::cout << "Enter " << meaning[i];
            std::cin >> data;
            file << " " << data;
        }
        std::cout << "Would you like to continue entering data (yes/no):";
        std::cin >> answer;


    }
    file.close();
    return 0;
}
