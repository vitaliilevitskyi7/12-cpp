#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;

    // Виведення першого рядка (початкові числа)
    for (int i = 1; i <= n; ++i) {
        std::cout << std::setw(6) << i;
    }
    std::cout << "\n";

    // Виведення розділювальної лінії
    for (int i = 1; i <= n; ++i) {
        std::cout << "------";
    }
    std::cout << "\n";

    // Виведення другого рядка (значення коренів)
    std::cout << std::fixed;
    for (int i = 1; i <= n; ++i) {
        double root = std::sqrt(i);
        
        // Перевірка, чи є корінь цілим числом (залишок від ділення на 1 дорівнює 0)
        if (std::fmod(root, 1.0) == 0.0) {
            std::cout << std::setw(6) << std::setprecision(0) << root;
        } else {
            std::cout << std::setw(6) << std::setprecision(2) << root;
        }
    }
    std::cout << "\n";

    return 0;
}
