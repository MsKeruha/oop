#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Book {
public:
    Book(std::string title, std::string author, int year) : title(title), author(author), year(year) {}

    void displayInfo() const {
        std::cout << "Книга: " << title << ", Автор: " << author << ", Рік: " << year << std::endl;
    }
    void edit() {
        cout << "Введіть нову назву книги: "; cin >> this->title;
        cout << "Введіть нового автора книги: "; cin >> this->author;
        cout << "Введіть новий рік написання книги: "; cin >> this->year;
    }
    // Оператор порівняння за назвою книги
    bool operator<(const Book& other) const {
        return title < other.title;
    }
    int isTitle(string other) {
        if (this->title == other) {
            return 1;
        }
        else {
            return 0;
        }
    }

private:
    std::string title;
    std::string author;
    int year;
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    std::vector<Book> library;

    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.push_back(Book("1984", "George Orwell", 1949));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951));

    std::cout << "Інформація про книги в бібліотеці:" << std::endl;
    for (const auto& book : library) {
        book.displayInfo();
    }

    // Використовуємо std::sort для сортування за назвою книги
    std::sort(library.begin(), library.end());

    std::cout << "\nБібліотека після сортування за назвою книги:" << std::endl;
    for (const auto& book : library) {
        book.displayInfo();
    }
    string edit;
    cout << "Введіть назву книги котру хочете редагувати: "; cin >> edit;
    for (int i = 0; i < library.size(); i++) {
        if (library[i].isTitle(edit)) {
            library[i].edit();
            break;
        }
    }
    string del;
    cin.ignore();
    cout << "Введіть назву книги котру хочете видалити: "; getline(cin, del);

    for (int i = 0; i < library.size(); i++) {
        if (library[i].isTitle(del)) {
            library.erase(library.begin() + i);
            break;
        }
    }
    for (const auto& book : library) {
        book.displayInfo();
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    setlocale(LC_ALL, "ukr");
    std::vector<std::string> favoriteFruits;

    std::cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << std::endl;
    std::cout << "Введіть свої улюблені фрукти (введіть '0', щоб завершити введення):" << std::endl;

    std::string fruit;
    while (true) {
        std::cout << "Фрукт: ";
        std::cin >> fruit;

        // Перевірка на вихід з гри
        if (fruit == "0") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }
    int prov;
    cout << "Сортувати по зростанню, чи зменшенню алфавіту? 1 - зростання, 2 - зменшення: "; cin >> prov;
    // Сортування фруктів за алфавітом
    std::sort(favoriteFruits.begin(), favoriteFruits.end());
    if (prov == 2) {
        reverse(favoriteFruits.begin(), favoriteFruits.end());
    }
    std::cout << "\nВаші улюблені фрукти в алфавітному порядку:" << std::endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        std::cout << favoriteFruit << std::endl;
    }

    std::cout << "Гра завершена. Дякуємо за участь!" << std::endl;

    return 0;
}

#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;
class Joke {
public:
    Joke(std::string text) : text(text), votes(0), totalRating(0) {}

    void tellJoke() const {
        std::cout << "Жарт: " << text << std::endl;
        std::cout << "Оцінка: " << std::fixed << std::setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << std::endl;
    }

    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        }
        else {
            std::cout << "Оцінка повинна бути від 1 до 5!" << std::endl;
        }
    }

    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }

private:
    std::string text;
    int votes;
    int totalRating;
};

int main() {
    setlocale(LC_ALL, "ukr");
    std::list<Joke> jokeList;
    int players;
    cout << "Введіть кількість гравців: "; cin >> players;
    // Додавання жартів до списку
    jokeList.push_back(Joke("Чому програмісти так погано сплять? Тому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Нікого робота програми не дивує так часто, як її творця!"));
    jokeList.push_back(Joke("Що робить програміст після розставання? Переходить на інший репозиторій!"));
    jokeList.push_back(Joke("Є два способи писати безпомилкові комп’ютерні програми. І лише третій — правильний."));

    std::cout << "Ласкаво просимо до програми для оцінювання жартів!" << std::endl;

    // Оцінювання жартів
    for (int i = 1; i < players + 1; i++) {
        cout << "Гравець " << i << " оцініть жарти" << endl;
        for (auto& joke : jokeList) {
            joke.tellJoke();

            int userRating;
            std::cout << "Ваша оцінка (1-5): ";
            std::cin >> userRating;

            joke.rateJoke(userRating);
        }
    }

    std::cout << "\nЖарти з високим рейтингом:" << std::endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}

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
