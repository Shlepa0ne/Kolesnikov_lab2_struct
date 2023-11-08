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
        cout << "�������� ������ �� ����������.\n\n";
        int option;
        while (getchar() != '\n');
        cout << "������� ���: ";
        cin >> cars[*num_cars].add_info.cust_data.name;
        cout << "������� �������: ";
        cin >> cars[*num_cars].add_info.cust_data.surname;
        cout << "������� ���������� �����: ";
        cin >> cars[*num_cars].add_info.cust_data.phone_number;
        cout << "������� ����� ����������: ";
        cin >> cars[*num_cars].add_info.car_data.car_brand;
        cout << "������� ��� ������� ����������: ";
        cin >> cars[*num_cars].add_info.car_data.year_of_release;
        cout << "������� �������� ����������: ";
        cin >> cars[*num_cars].add_info.car_data.state_number;

        cout << "�������� ��� ��������� (1. ����������; 2. ���������; 3. �������������): ";
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

        cout << "�������� ��� ������� (1. ��������; 2. ������; 3. ������): ";
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
        cout << "������� ���� ������: ";
        cin >> cars[*num_cars].car_body.color;

        cout << "�������� �������� ������ (1. ��������; 2. �����; 3. �����������): ";
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
        cout << "��������� ������������ ����� �������.\n\n";
    }
}
void Output(Car* cars, int num_cars)
{
    if (num_cars > 0)
    {
        cout << "����� ���� �������.\n\n";
        for (int counter = 0; counter < num_cars; counter++)
        {
            cout << "����� �" << counter + 1 << "\n";
            cout << "���: " << cars[counter].add_info.cust_data.name << "\n";
            cout << "�������: " << cars[counter].add_info.cust_data.surname << "\n";
            cout << "���������� �����: " << cars[counter].add_info.cust_data.phone_number << "\n";
            cout << "����� ����������: " << cars[counter].add_info.car_data.car_brand << "\n";
            cout << "��� ������� ����������: " << cars[counter].add_info.car_data.year_of_release << "\n";
            cout << "�������� ����������: " << cars[counter].add_info.car_data.state_number << "\n";
            cout << "��� ���������: ";
            switch (cars[counter].engine)
            {
            case petrol:
                printf("����������\n");
                break;
            case diesel:
                printf("���������\n");
                break;
            case electric:
                printf("�������������\n");
                break;
            default:
                printf("����������\n");
                break;
            }
            cout << "��� �������: ";
            switch (cars[counter].wd)
            {
            case fwd:
                printf("��������\n");
                break;
            case rwd:
                printf("������\n");
                break;
            case awd:
                printf("������\n");
                break;
            default:
                printf("����������\n");
                break;
            }
            cout << "���� ������: " << cars[counter].car_body.color << "\n";
            cout << "�������� ������: ";
            switch (cars[counter].car_body.material)
            {
            case aluminum:
                printf("��������\n");
                break;
            case steel:
                printf("�����\n");
                break;
            case carbon_fiber:
                printf("�����������\n");
                break;
            default:
                printf("����������\n");
                break;
            }
            cout << "-----------------------------------\n\n";
        }
    }
    else
    {
        cout << "������ �� �������!\n\n";
    }
}
