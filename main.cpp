#include <iostream>
#include <fstream>
#include <string>


bool check (std::string text) {
    if ((stoi(text.substr(0, 2)) > 0 && stoi(text.substr(0, 2)) <= 31) &&
        (stoi(text.substr(3, 2)) == 1 || stoi(text.substr(3, 2)) == 3 ||
            stoi(text.substr(3, 2)) == 5 || stoi(text.substr(0, 2)) == 7 ||
                stoi(text.substr(3, 2)) == 8 || stoi(text.substr(3, 2)) == 10 ||
                    stoi(text.substr(3, 2)) == 12) && stoi(text.substr(6)) == 2022) {return true;}
    else if ((stoi(text.substr(0, 2)) > 0 && stoi(text.substr(0, 2)) <= 30) &&
        (stoi(text.substr(3, 2)) == 4 || stoi(text.substr(3, 2)) == 6 ||
            stoi(text.substr(3, 2)) == 9 || stoi(text.substr(3, 2)) == 11) &&
                stoi(text.substr(6)) == 2022) {return true;}
    else if ((stoi(text.substr(0, 2)) > 0 && stoi(text.substr(0, 2)) <= 28) &&
        (stoi(text.substr(3, 2)) == 2) && stoi(text.substr(6)) == 2022) {return true;}
    else { return false;}
}
int main() {
    std::string data, answer = "yes";
    std::ofstream file;
    std::cout << "Enter the data: " << std::endl;
    std::string meaning[4]{"Name ", "Surname ", "Date ", "Sum "};
    std::string preparation[4];
    file.open("P:\\Statement.txt", std::ios::app);
    file << "\t\tMeaning" << "\n";
    while (answer == "yes") {
        for (int i = 0; i < 4; i++) {
            std::cout << "Enter " << meaning[i];
            std::cin >> data;
            if (i == 2) {
                if (!check(data)) {
                    std::cout << "There is an error in the file!\n";
                    i = -1;
                }
            }
            preparation[i] = data;
        }
        for (int i = 0; i < 4; i++) {
            file << " " << preparation[i];
        }
        file << "\n";
        std::cout << "Would you like to continue entering data (yes/no):";
        std::cin >> answer;


    }
    file.close();
    return 0;
}
