#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    // ��������� �������� ��� ��������� ������� ���� ��������
    std::map<std::string, double> studentGrades;
    vector<string> search1;
    vector<double> search2;
    // ��������� ����� �� ��������
    studentGrades["Ann"] = 4.5;
    studentGrades["Borys"] = 3.8;
    studentGrades["Catrine"] = 4.2;
    studentGrades["Dmytro"] = 4.0;

    // ���� ����� ��� ��������
    std::cout << "���������� ��� ��������:" << std::endl;
    for (const auto& student : studentGrades) {
        std::cout << student.first << ": " << student.second << std::endl;
    }

    // ����� � ���� ���������� ���� ��� ������� ��������
    while (true) {
        std::string searchStudent;
        std::cout << "\n������ ��'� �������� ��� ������ ���������� ����, ������ 0 ��� ������: ";
        std::cin >> searchStudent;
        search1.push_back(searchStudent);
        auto it = studentGrades.find(searchStudent);
        if (searchStudent == "0") {
            break;
        }
        if (it != studentGrades.end()) {
            std::cout << "������� ��� �������� " << searchStudent << ": " << it->second << std::endl;
            search2.push_back(it->second);
        }
        else {
            std::cout << "������� � ������ " << searchStudent << " �� ���������." << std::endl;
            search2.push_back(NULL);
        }
    }
    for (int i = 0; i < search1.size() - 1; i++) {
        cout << "�����: " << search1[i] << " ���������: ";
        if (search2[i] != NULL) {
            cout << search2[i];
        }
        else {
            cout << "�������";
        }
        cout << endl;
    }
    return 0;
}