#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include "Car.h"
#define max_cars 100

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Car cars[max_cars];

    int num_cars = 0;
    int quit = 0;
    int option;
    while(!quit)
    {
        cout << "Выберите действие:\n";
        cout << " 1. Создать запись об автомобиле\n";
        cout << " 2. Редактировать конкретную запись\n";
        cout << " 3. Вывести все существующие записи\n";
        cout << " 4. Вывести конкретную запись\n";
        cout << " 5. Удалить конкретную запись\n";
        cout << " 0. Выйти\n > ";

        if (scanf("%d", &option) == 1)
        {
            system("cls");
            switch (option)
            {
            case 1:
                Input(cars, &num_cars);
                break;
            case 2:
                cout << "Редактирование находится в разработке!\n\n";
                break;
            case 3:
                Output(cars, num_cars);
                break;
            case 4:
                cout << "Вывод конкретной записи находится в разработке!\n\n";
                break;
            case 5:
                cout << "Удаление находится в разработке!\n\n";
                break;
            case 0:
                cout << "Выход.\n";
                quit = 1;
                break;
            default:
                cout << "Некорректный ввод. Попробуйте еще раз\n\n";
                break;
            }
        }
        else
        {
            system("cls");
            cout << "Некорректный ввод. Попробуйте еще раз\n\n";
            while (getchar() != '\n');
        }
    }
}
