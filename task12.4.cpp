#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Помилка: некоректний розмір.\n";
        return 1;
    }

    // Динамічний масив цілих чисел m_i
    int* m = new int[n];
    std::cout << "Введіть " << n << " цілих чисел m_i:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> m[i];
    }

    // Перевірка наявності та коректності вхідного файлу
    std::ifstream infile("input.txt");
    if (!infile.is_open()) {
        std::cout << "Помилка: файл 'input.txt' не знайдено.\n";
        delete[] m;
        return 1;
    }

    double* x = new double[n];
    for (int i = 0; i < n; ++i) {
        if (!(infile >> x[i])) {
            std::cout << "Помилка: некоректні дані або недостатньо чисел у файлі 'input.txt'.\n";
            delete[] m;
            delete[] x;
            return 1;
        }
    }
    infile.close();

    // Обчислення та виведення результатів у текстовий файл
    std::ofstream outfile("output.txt");
    if (!outfile.is_open()) {
        std::cout << "Помилка створення вихідного файлу.\n";
        delete[] m;
        delete[] x;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        double result = std::pow(x[i], m[i]);
        outfile << result << "\n";
    }
    outfile.close();

    std::cout << "Розрахунок завершено. Результати збережено в 'output.txt'.\n";

    delete[] m;
    delete[] x;
    return 0;
}
