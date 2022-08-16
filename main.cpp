#include <iostream>
#include <fstream>
#include <string>


bool check (std::string text) {
    std::string day = " ", month = " ", year = " ";
    for (int i = 0; i < text.length(); i++) {
        if (i < 2) {
            day += text[i];
        }
        if (i > 2 && i < 5) {
            month += text[i];
        }
        if (i > 5) {
            year += text[i];
        }
    }
    std::cout << "day " << day << " Month " << month << " Year " << year << "\n";
    if ((stoi(day) > 0 && stoi(day) <= 31) && (stoi(month) == 1 || stoi(month) == 3 || stoi(month) == 5 || stoi(month) == 7 || stoi(month) == 8 || stoi(month) == 10 || stoi(month) == 12) && stoi(year) == 2022) {return true;}
    else if ((stoi(day) > 0 && stoi(day) <= 30) && (stoi(month) == 4 || stoi(month) == 6 || stoi(month) == 9 || stoi(month) == 11) && stoi(year) == 2022) {return true;}
    else if ((stoi(day) > 0 && stoi(day) <= 28) && (stoi(month) == 2) && stoi(year) == 2022) {return true;}
    else {
        return false;
    }
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
        std::cout << "Would you like to continue entering data (yes/no):";
        std::cin >> answer;


    }
    file.close();
    return 0;
}
