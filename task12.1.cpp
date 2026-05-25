#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x, y;
    std::cout << "Введіть дійсне число x: ";
    std::cin >> x;
    std::cout << "Введіть дійсне число y: ";
    std::cin >> y;

    double result = std::pow(x, y);

    // Виведення в десятковому представленні
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Десяткове представлення: " << result << "\n";

    // Виведення в науковому представленні
    std::cout << std::scientific;
    std::cout << "Наукове представлення:  " << result << "\n";

    return 0;
}
