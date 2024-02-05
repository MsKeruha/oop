#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    // Створення словника для зберігання середніх балів студентів
    std::map<std::string, double> studentGrades;
    vector<string> search1;
    vector<double> search2;
    // Додавання даних до словника
    studentGrades["Ann"] = 4.5;
    studentGrades["Borys"] = 3.8;
    studentGrades["Catrine"] = 4.2;
    studentGrades["Dmytro"] = 4.0;

    // Вивід даних про студентів
    std::cout << "Інформація про студентів:" << std::endl;
    for (const auto& student : studentGrades) {
        std::cout << student.first << ": " << student.second << std::endl;
    }

    // Пошук і вивід середнього балу для певного студента
    while (true) {
        std::string searchStudent;
        std::cout << "\nВведіть ім'я студента для пошуку середнього балу, введіть 0 для виходу: ";
        std::cin >> searchStudent;
        search1.push_back(searchStudent);
        auto it = studentGrades.find(searchStudent);
        if (searchStudent == "0") {
            break;
        }
        if (it != studentGrades.end()) {
            std::cout << "Середній бал студента " << searchStudent << ": " << it->second << std::endl;
            search2.push_back(it->second);
        }
        else {
            std::cout << "Студент з іменем " << searchStudent << " не знайдений." << std::endl;
            search2.push_back(NULL);
        }
    }
    for (int i = 0; i < search1.size() - 1; i++) {
        cout << "Запит: " << search1[i] << " Результат: ";
        if (search2[i] != NULL) {
            cout << search2[i];
        }
        else {
            cout << "жодного";
        }
        cout << endl;
    }
    return 0;
}