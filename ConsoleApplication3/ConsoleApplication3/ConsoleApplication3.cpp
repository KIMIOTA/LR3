#include <iostream>
#include <algorithm>

class TFraction {
private:
    int numerator;   // Чисельник
    int denominator; // Знаменник

    // Метод для знаходження найбільшого спільного дільника (НСД)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Конструктор без параметрів
    TFraction() : numerator(0), denominator(1) {}

    // Конструктор з параметрами
    TFraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "Знаменник не може бути рівним нулю. Знаменник буде встановлено на 1." << std::endl;
            denominator = 1;
        }

        // Скорочуємо дріб
        int commonDivisor = gcd(abs(numerator), abs(denominator));
        numerator /= commonDivisor;
        denominator /= commonDivisor;

        // Встановлюємо вірний знак
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Конструктор копіювання
    TFraction(const TFraction& other) : numerator(other.numerator), denominator(other.denominator) {}

    // Метод для введення даних
    void input() {
        std::cout << "Введіть чисельник: ";
        std::cin >> numerator;
        do {
            std::cout << "Введіть знаменник (не нуль): ";
            std::cin >> denominator;
        } while (denominator == 0);

        // Скорочуємо дріб
        int commonDivisor = gcd(abs(numerator), abs(denominator));
        numerator /= commonDivisor;
        denominator /= commonDivisor;

        // Встановлюємо вірний знак
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Метод для виведення даних
    void display() const {
        std::cout << numerator << "/" << denominator;
    }

    // Метод для скорочення дробу
    void simplify() {
        int commonDivisor = gcd(abs(numerator), abs(denominator));
        numerator /= commonDivisor;
        denominator /= commonDivisor;

        // Встановлюємо вірний знак
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Перевантаження оператора додавання (+)
    TFraction operator+(const TFraction& other) const {
        int resultNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int resultDenominator = denominator * other.denominator;
        return TFraction(resultNumerator, resultDenominator);
    }

    // Перевантаження оператора віднімання (-)
    TFraction operator-(const TFraction& other) const {
        int resultNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int resultDenominator = denominator * other.denominator;
        return TFraction(resultNumerator, resultDenominator);
    }

    // Перевантаження оператора множення (*)
    TFraction operator*(const TFraction& other) const {
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
        return TFraction(resultNumerator, resultDenominator);
    }

    // Перевантаження оператора ділення (/)
    TFraction operator/(const TFraction& other) const {
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        return TFraction(resultNumerator, resultDenominator);
    }
};

int main() {
    TFraction fraction1, fraction2;

    std::cout << "Введення першого дробу:" << std::endl;
    fraction1.input();

    std::cout << "Введення другого дробу:" << std::endl;
    fraction2.input();

    // Виведення дробів
    std::cout << "Перший дріб: ";
    fraction1.display();
    std::cout << std::endl;

    std::cout << "Другий дріб: ";
    fraction2.display();
    std::cout << std::endl;

    // Виконання операцій
    TFraction sum = fraction1 + fraction2;
    TFraction diff = fraction1 - fraction2;
    TFraction product = fraction1 * fraction2;
    TFraction quotient = fraction1 / fraction2;

    // Виведення результатів
    std::cout << "Сума: ";
    sum.display();
    std::cout << std::endl;

    std::cout << "Різниця: ";
    diff.display();
    std::cout << std::endl;

    std::cout << "Добуток: ";
    product.display();
    std::cout << std::endl;

    std::cout << "Частка: ";
    quotient.display();
    std::cout << std::endl;

    return 0;
}
