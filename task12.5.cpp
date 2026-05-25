#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    // Налаштування швидкого введення-виведення для великих потоків даних
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned long long num;
    std::vector<unsigned long long> numbers;

    // Зчитування чисел до кінця вхідного потоку (EOF)
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    // Налаштування формату виведення: 3 знаки після коми
    std::cout << std::fixed << std::setprecision(3);

    // Виведення квадратних коренів починаючи з останнього числа
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        double root = std::sqrt(static_cast<double>(*it));
        std::cout << root << "\n";
    }

    return 0;
}
