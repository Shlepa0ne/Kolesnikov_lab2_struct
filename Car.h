#pragma once

#define max_cars 100
using namespace std;

enum Engine
{
    petrol,
    diesel,
    electric,
    unknown_engine
};
enum WheelDrive
{
    fwd,
    rwd,
    awd,
    unknown_wd
};
enum Material
{
    aluminum,
    steel,
    carbon_fiber,
    unknown_material
};

typedef struct
{
    string name;
    string surname;
    string phone_number;
} CustomerData;
typedef struct
{
    string car_brand;
    string year_of_release;
    string state_number;
} CarData;
typedef struct
{
    CustomerData cust_data;
    CarData car_data;
} AdditionalInformation;
typedef struct
{
    string color;
    Material material;
} CarBody;
typedef struct
{
    AdditionalInformation add_info;
    Engine engine;
    WheelDrive wd;
    CarBody car_body;
} Car;

void Input(Car* cars, int* num_cars)
{
    if (*num_cars < max_cars)
    {
        cout << "Создание записи об автомобиле.\n\n";
        int option;
        while (getchar() != '\n');
        cout << "Введите имя: ";
        cin >> cars[*num_cars].add_info.cust_data.name;
        cout << "Введите фамилию: ";
        cin >> cars[*num_cars].add_info.cust_data.surname;
        cout << "Введите телефонный номер: ";
        cin >> cars[*num_cars].add_info.cust_data.phone_number;
        cout << "Введите марку автомобиля: ";
        cin >> cars[*num_cars].add_info.car_data.car_brand;
        cout << "Введите год выпуска автомобиля: ";
        cin >> cars[*num_cars].add_info.car_data.year_of_release;
        cout << "Введите госномер автомобиля: ";
        cin >> cars[*num_cars].add_info.car_data.state_number;

        cout << "Выберите тип двигателя (1. бензиновый; 2. дизельный; 3. электрический): ";
        cars[*num_cars].engine = unknown_engine;
        if (scanf("%d", &option) == 1)
        {
            switch (option)
            {
            case 1:
                cars[*num_cars].engine = petrol;
                break;
            case 2:
                cars[*num_cars].engine = diesel;
                break;
            case 3:
                cars[*num_cars].engine = electric;
                break;
            default:
                break;
            }
        }

        cout << "Выберите тип привода (1. передний; 2. задний; 3. полный): ";
        cars[*num_cars].wd = unknown_wd;
        if (scanf("%d", &option) == 1)
        {
            switch (option)
            {
            case 1:
                cars[*num_cars].wd = fwd;
                break;
            case 2:
                cars[*num_cars].wd = rwd;
                break;
            case 3:
                cars[*num_cars].wd = awd;
                break;
            default:
                break;
            }
        }

        while (getchar() != '\n');
        cout << "Введите цвет кузова: ";
        cin >> cars[*num_cars].car_body.color;

        cout << "Выберите материал кузова (1. алюминий; 2. сталь; 3. углеволокно): ";
        cars[*num_cars].car_body.material = unknown_material;
        if (scanf("%d", &option) == 1)
        {
            switch (option)
            {
            case 1:
                cars[*num_cars].car_body.material = aluminum;
                break;
            case 2:
                cars[*num_cars].car_body.material = steel;
                break;
            case 3:
                cars[*num_cars].car_body.material = carbon_fiber;
                break;
            default:
                break;
            }
        }

        (*num_cars)++;
        system("cls");
    }
    else
    {
        cout << "Достигнут максимальный лимит записей.\n\n";
    }
}
void Output(Car* cars, int num_cars)
{
    if (num_cars > 0)
    {
        cout << "Вывод всех записей.\n\n";
        for (int counter = 0; counter < num_cars; counter++)
        {
            cout << "Заказ №" << counter + 1 << "\n";
            cout << "Имя: " << cars[counter].add_info.cust_data.name << "\n";
            cout << "Фамилия: " << cars[counter].add_info.cust_data.surname << "\n";
            cout << "Телефонный номер: " << cars[counter].add_info.cust_data.phone_number << "\n";
            cout << "Марка автомобиля: " << cars[counter].add_info.car_data.car_brand << "\n";
            cout << "Год выпуска автомобиля: " << cars[counter].add_info.car_data.year_of_release << "\n";
            cout << "Госномер автомобиля: " << cars[counter].add_info.car_data.state_number << "\n";
            cout << "Тип двигателя: ";
            switch (cars[counter].engine)
            {
            case petrol:
                printf("Бензиновый\n");
                break;
            case diesel:
                printf("Дизельный\n");
                break;
            case electric:
                printf("Электрический\n");
                break;
            default:
                printf("Неизвестен\n");
                break;
            }
            cout << "Тип привода: ";
            switch (cars[counter].wd)
            {
            case fwd:
                printf("Передний\n");
                break;
            case rwd:
                printf("Задний\n");
                break;
            case awd:
                printf("Полный\n");
                break;
            default:
                printf("Неизвестен\n");
                break;
            }
            cout << "Цвет кузова: " << cars[counter].car_body.color << "\n";
            cout << "Материал кузова: ";
            switch (cars[counter].car_body.material)
            {
            case aluminum:
                printf("Алюминий\n");
                break;
            case steel:
                printf("Сталь\n");
                break;
            case carbon_fiber:
                printf("Углеволокно\n");
                break;
            default:
                printf("Неизвестен\n");
                break;
            }
            cout << "-----------------------------------\n\n";
        }
    }
    else
    {
        cout << "Записи не найдены!\n\n";
    }
}
