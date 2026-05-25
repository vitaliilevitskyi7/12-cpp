#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <cmath>

int main() {
    std::string input;
    std::cout << "Введіть рядок (наприклад, A=123.45, B=-2.5E+3 C=0.004):\n";
    std::getline(std::cin, input);

    // Регулярний вираз для пошуку чисел у форматі A=..., B=..., C=...
    // Шаблон розпізнає знаки, десяткові крапки та експоненту E
    std::regex regex_A("A=([+-]?\\d*\\.?\\d+(?:[eE][+-]?\\d+)?)");
    std::regex regex_B("B=([+-]?\\d*\\.?\\d+(?:[eE][+-]?\\d+)?)");
    std::regex regex_C("C=([+-]?\\d*\\.?\\d+(?:[eE][+-]?\\d+)?)");

    std::smatch match_A, match_B, match_C;

    // Перевірка наявності всіх трьох компонентів у рядку
    if (std::regex_search(input, match_A, regex_A) &&
        std::regex_search(input, match_B, regex_B) &&
        std::regex_search(input, match_C, regex_C)) {
        
        try {
            // Перетворення виділених текстових підрядків у дійсні числа
            double a = std::stod(match_A[1].str());
            double b = std::stod(match_B[1].str());
            double c = std::stod(match_C[1].str());

            std::cout << "\nЗчитані значення:\nA = " << a << "\nB = " << b << "\nC = " << c << "\n\n";

            // Перевірка ОДЗ для середнього гармонічного (знаменники не можуть бути нулями)
            if (a == 0.0 || b == 0.0 || c == 0.0) {
                std::cout << "Помилка: Одне з чисел дорівнює 0. Обчислення середнього гармонічного неможливе.\n";
                return 0;
            }

            double denominator = (1.0 / a) + (1.0 / b) + (1.0 / c);
            
            if (denominator == 0.0) {
                std::cout << "Помилка: Сума обернених значень дорівнює 0. Ділення на нуль.\n";
                return 0;
            }

            // Формула середнього гармонічного для трьох чисел
            double H = 3.0 / denominator;

            // Виведення результатів
            std::cout << "--- РЕЗУЛЬТАТИ ---" << std::endl;
            std::cout << std::fixed << std::setprecision(6);
            std::cout << "Звичайний формат: " << H << std::endl;

            std::cout << std::scientific << std::setprecision(6);
            std::cout << "Науковий формат:  " << H << std::endl;

        } catch (const std::exception& e) {
            std::cout << "Помилка: Неможливо коректно перетворити знайдені символи в дійсні числа.\n";
        }
    } else {
        std::cout << "Помилка: Рядок не відповідає заданому шаблону структури або пропущено змінні.\n";
    }

    return 0;
}
