#include <iostream>
#include <cstdlib>  // Для генерации случайных чисел
#include <ctime>    // Для задания времени как источника случайных чисел
#include <limits>   // Для использования std::numeric_limits

using namespace std;

int generateRandomNumber() {
    return rand() % 100 + 1;  
}

int main() {
    srand(time(0));  
    int randomNumber = generateRandomNumber();  
    int guess;  
    int attempts = 0;  
    const int maxAttempts = 10;  

    cout << "Угадайте число от 1 до 100!" << endl;

    while (attempts < maxAttempts) {
        cout << "Попытка " << (attempts + 1) << " из " << maxAttempts << ": ";
        cin >> guess;

        if (cin.fail() || guess < 1 || guess > 100) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Ошибка! Введите число в диапазоне от 1 до 100." << endl;
            continue;  
        }

        attempts++;

        if (guess < randomNumber) {
            cout << "Слишком маленькое число!" << endl;
        } else if (guess > randomNumber) {
            cout << "Слишком большое число!" << endl;
        } else {
            cout << "Поздравляю, вы угадали число " << randomNumber << "!" << endl;
            break;  
        }

        if (attempts == maxAttempts) {
            cout << "Вы не угадали. Загаданное число было " << randomNumber << "." << endl;
        }
    }

    return 0;
}