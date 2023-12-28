#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
 
using namespace std;

void rules();
void singlePlayerMode(string playerName, int& balance);
void twoPlayerMode(string player1, int& balance1, string player2, int& balance2);

int main() {
    char choice;
    int balance1 = 0, balance2 = 0;
    string playerName, player1, player2;

    srand(time(0));
    cout << "\n\t\t\t\t\t========ДОБРО ПОЖАЛОВАТЬ В МИР КАЗИНО=======\n\n";

    cout << "Выберите режим:" << endl;
    cout << "1) Одиночный игрок" << endl;
    cout << "2) Два игрока" << endl;
    cout << "Введите ваш выбор: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case '1':
        cout << "\n\nКак вас зовут: ";
        getline(cin, playerName);
        do {
            cout << "\nВведите начальный баланс для игры: $";
            cin >> balance1;
            if (balance1 < 0 || balance1 == 0)
                cout << "Баланс не может быть меньше нуля или равным нулю" << endl;
        } while (balance1 < 0 || balance1 == 0);
        singlePlayerMode(playerName, balance1);
        break;
    case '2':
        cout << "\nВведите имя первого игрока: ";
        getline(cin, player1);
        do {
            cout << "\nВведите начальный баланс для " << player1 << ": $";
            cin >> balance1;
            if (balance1 < 0 || balance1 == 0)
                cout << "Баланс не может быть меньше нуля или равным нулю" << endl;
        } while (balance1 < 0 || balance1 == 0);
        cin.ignore();

        cout << "\nВведите имя второго игрока: ";
        getline(cin, player2);
        do {
            cout << "\nВведите начальный баланс для " << player2 << ": $";
            cin >> balance2;
            if (balance2 < 0 || balance2 == 0)
                cout << "Баланс не может быть меньше нуля или равным нулю" << endl;
        } while (balance2 < 0 || balance2 == 0);
        twoPlayerMode(player1, balance1, player2, balance2);
        break;
    default:
        cout << "Неверный выбор. До свидания!\n";
        return 1;
    }

    cout << "\n\nСпасибо за игру!\n\n";
    return 0;
}

void rules() {
    system("cls");
    cout << "\t\t======rules УГАДЫВАНИЯ ЧИСЕЛ В КАЗИНО!======\n";
    cout << "\t1. Выберите число от 1 до 10\n";
    cout << "\t2. Победитель получает 10 раз ставку\n";
    cout << "\t3. Неправильная ставка означает потерю суммы вашей ставки\n\n";
}

void singlePlayerMode(string playerName, int& balance) {
    int bettingAmount, guess, dice;
    char choice;

    do {
        system("cls");
        rules();
        cout << "\n\nВаш текущий баланс: $ " << balance << "\n";

        do {
            cout << "Привет, " << playerName << ", введите сумму для ставки: $";
            cin >> bettingAmount;
            if (bettingAmount > balance || bettingAmount < 0 || bettingAmount == 0)
                cout << "Ставка не может быть больше текущего баланса или равная 0!\n" << "\nВведите ставку заново\n ";
        } while (bettingAmount > balance || bettingAmount < 0 || bettingAmount == 0);

        do {
            cout << "Угадайте число от 1 до 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nЧисло должно быть от 1 до 10\n"
                << "Введите число заново:\n ";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess) {
            cout << "\n\nВам повезло!! Вы выиграли $ " << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else {
            cout << "Увы, повезет в следующий раз!! Вы проиграли $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }

        cout << "\nВыигрышное число было : " << dice << "\n";
        cout << "\n" << playerName << ", у вас баланс $ " << balance << "\n";

        if (balance == 0) {
            cout << "У вас нет денег для игры ";
            break;
        }

        cout << "\n\n-->Хотите сыграть еще раз (y/n)? ";
        cin >> choice;
        cin.ignore(); // Чтобы скорректировать ввод
    } while (choice == 'Y' || choice == 'y');
}

void twoPlayerMode(string player1, int& balance1, string player2, int& balance2) {
    int guess1, guess2, dice;
    int bet1, bet2;
    int diff1, diff2;
    char choice;

        do {
            system("cls");
            rules();
            cout << "\n\nБаланс " << player1 << ": $ " << balance1 << "\n";
            cout << "Баланс " << player2 << ": $ " << balance2 << "\n";

            cout << "\nВведите вашу ставку, " << player1 << ": $";
            do {
                cin >> bet1;
                if (bet1 > balance1 || bet1 < 0|| bet1==0) {
                    cout << "Ставка не может быть больше вашего баланса или равна 0! Введите ставку заново: $";
                }
            } while (bet1 > balance1 || bet1 < 0 || bet1 == 0);

            cout << "\nВведите вашу ставку, " << player2 << ": $";
            do {
                cin >> bet2;
                if (bet2 > balance2 || bet2 < 0 || bet2 == 0) {
                    cout << "Ставка не может быть больше вашего баланса или равна 0! Введите ставку заново: $";
                }
            } while (bet2 > balance2 || bet2 < 0 || bet2 == 0);

            cout << "\n" << player1 << ", введите ваше число от 1 до 10: ";
            do {
                cout << "Угадайте число от 1 до 10 :";
                cin >> guess1;
                if (guess1 <= 0 || guess1 > 10)
                    cout << "\nЧисло должно быть от 1 до 10\n"
                    << "Введите число заново:\n ";
            } while (guess1 <= 0 || guess1 > 10);
            cout << "\n" << player2 << ", введите ваше число от 1 до 10: ";
            do {
                cout << "Угадайте число от 1 до 10 :";
                cin >> guess2;
                if (guess2 <= 0 || guess2 > 10)
                    cout << "\nЧисло должно быть от 1 до 10\n"
                    << "Введите число заново:\n ";
            } while (guess2 <= 0 || guess2 > 10);

            dice = rand() % 10 + 1;
            cout << "\nВыигрышное число: " << dice << "\n";

            diff1 = abs(dice - guess1);
            diff2 = abs(dice - guess2);

            if (diff1 < diff2) {
                cout << player1 << " выиграл! Его число было ближе к загаданному.\n";
                balance1 += bet1;
                balance2 -= bet2;
            }
            else if (diff2 < diff1) {
                cout << player2 << " выиграл! Его число было ближе к загаданному.\n";
                balance2 += bet2;
                balance1 -= bet1;
            }
            else {
                cout << "Ничья! Оба числа равноудалены от загаданного числа.\n";
            }

            cout << "\nБаланс " << player1 << ": $ " << balance1 << "\n";
            cout << "Баланс " << player2 << ": $ " << balance2 << "\n";

            cout << "\n\n-->Хотите сыграть еще раз (y/n)? ";
            cin >> choice;
            cin.ignore(); // Чтобы скорректировать ввод

        } while (choice == 'Y' || choice == 'y');
}