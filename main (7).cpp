#include <iostream>
#include <array>
#include <cmath>
using namespace std;

// Декларація функцій
void Proc30();
void Boolean17();
void Integer4();
void showMenu();

bool InputAndValidate(int& A, int& B); // Для Integer4
bool InputAndValidate(int& number);   // Для Boolean17
bool IsPalindrome(int K);             // Для Proc30
bool IsOddThreeDigit(int number);     // Для Boolean17
int CalculateSegments(int A, int B);  // Для Integer4
void OutputResult(int count);         // Для Integer4

// Головна функція
int main() {
    showMenu(); // Запуск меню вибору задач
    return 0;
}

// Функція меню вибору завдань
void showMenu() {
    int choice;
    do {
        cout << "\nВиберіть задачу для виконання або 0 для виходу:\n";
        cout << "1 - Proc30 (перевірка паліндромів у наборі чисел)\n";
        cout << "2 - Boolean17 (перевірка, чи число є непарним тризначним)\n";
        cout << "3 - Integer4 (підрахунок кількості відрізків)\n";
        cout << "0 - Завершити програму\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Proc30();
                break;
            case 2:
                Boolean17();
                break;
            case 3:
                Integer4();
                break;
            case 0:
                cout << "Програма завершена." << endl;
                break;
            default:
                cout << "Помилка: невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (choice != 0);
}

// Proc30: Перевірка паліндромів
bool IsPalindrome(int K) {
    if (K <= 0 || K >= 1000) {
        return false; // Перевірка на допустимий діапазон
    }
    int hundreds = K / 100;        // Отримання сотень
    int units = K % 10;           // Отримання одиниць
    return hundreds == units;     // Перевірка на паліндромність
}

void Proc30() {
    array<int, 5> numbers; // Масив для зберігання 5 чисел
    cout << "Введіть 5 цілих додатних чисел (0 < K < 1000):\n";

    // Ввід чисел
    for (int i = 0; i < 5; ++i) {
        cin >> numbers[i];
        if (numbers[i] <= 0 || numbers[i] >= 1000) {
            cerr << "Число має бути в діапазоні 0 < K < 1000. Спробуйте ще раз.\n";
            return;
        }
    }

    // Підрахунок паліндромів
    int palindromeCount = 0;
    for (int number : numbers) {
        if (IsPalindrome(number)) {
            ++palindromeCount;
        }
    }

    cout << "Кількість паліндромів у наборі: " << palindromeCount << endl;
}

// Boolean17: Перевірка, чи число є непарним тризначним
bool InputAndValidate(int& number) {
    cout << "Введіть ціле додатне число: ";
    cin >> number;

    if (number < 100 || number > 999) {
        cerr << "Помилка: Число має бути тризначним та додатним.\n";
        return false;
    }

    return true;
}

bool IsOddThreeDigit(int number) {
    return (number % 2 != 0); // Перевірка на непарність
}

void Boolean17() {
    int number;

    // Введення та перевірка даних
    if (!InputAndValidate(number)) {
        return; // Завершити програму у разі помилки
    }

    // Розрахунок результату
    if (IsOddThreeDigit(number)) {
        cout << "Висловлювання істинне: Число є непарним тризначним.\n";
    } else {
        cout << "Висловлювання хибне: Число не є непарним тризначним.\n";
    }
}

// Integer4: Підрахунок кількості відрізків
bool InputAndValidate(int& A, int& B) {
    cout << "Введіть два цілі додатні числа A і B (A > B): \n";
    cin >> A >> B;

    if (A <= 0 || B <= 0) {
        cerr << "Помилка: Числа повинні бути додатними.\n";
        return false;
    }

    if (A <= B) {
        cerr << "Помилка: A повинно бути більше за B.\n";
        return false;
    }

    return true;
}

int CalculateSegments(int A, int B) {
    return A / B; // Кількість відрізків B на відрізку A
}

void OutputResult(int count) {
    cout << "Кількість відрізків довжиною B, які можна розмістити на відрізку A: " << count << endl;
}

void Integer4() {
    int A, B;

    // Введення та перевірка даних
    if (!InputAndValidate(A, B)) {
        return; // Завершити програму у разі помилки
    }

    // Обчислення результату
    int count = CalculateSegments(A, B);

    // Виведення результату
    OutputResult(count);
}
