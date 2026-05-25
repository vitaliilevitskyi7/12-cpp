#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cout << "Введіть коефіцієнт кількості чисел n: ";
    std::cin >> n;

    std::cout << "Введіть " << 10 * n << " цифр поспіль (без пробілів):\n";
    std::vector<unsigned long long> numbers(n);
    unsigned long long sum = 0;

    for (int i = 0; i < n; ++i) {
        std::string digit_block = "";
        for (int j = 0; j < 10; ++j) {
            char ch;
            std::cin >> ch;
            digit_block += ch;
        }
        // Перетворення 10-значного рядка в число
        numbers[i] = std::stoull(digit_block);
        sum += numbers[i];
    }

    std::cout << "Сума введених чисел: " << sum << std::endl;
    return 0;
}
