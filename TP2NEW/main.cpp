#include <iostream>
#include <windows.h>
#include "Keeper.h"




//������� ��� ������� �������
void task_2(std::string filename) {
    char choice;
    std::ifstream file(filename);
    if (file.is_open()) {
        int i = 0;
        char buff;
        char prev = ' ';
        while (!file.eof()) {
            file.get(buff);
            switch (buff) {
            case '1':
                std::cout << " ���� ";
                break;
            case '2':
                std::cout << " ��� ";
                break;
            case '3':
                std::cout << " ��� ";
                break;
            case '4':
                std::cout << " ������ ";
                break;
            case '5':
                std::cout << " ���� ";
                break;
            case'6':
                std::cout << " ����� ";
                break;
            case '7':
                std::cout << " ���� ";
                break;
            case '8':
                std::cout << " ������ ";
                break;
            case '9':
                std::cout << " ������ ";
                break;
            case '0':
                std::cout << " ���� ";
                break;
            default:
                if (buff == ' ' && prev == '.') {
                    std::cout << std::endl;
                }
                std::cout << buff;
                break;
            }
            prev = buff;
        }
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
A:
    while (true) {
        system("cls");
        std::cout << "Menu:" << std::endl;
        std::cout << "1. ������� 1" << std::endl;
        std::cout << "2. ������� 2" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cout << "��� �����: ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            NOTE buffer;
            Keeper keeper;
            std::string filename = "";
            while (true) {
                system("cls");
                std::cout << "Menu task 1: " << std::endl;
                std::cout << "1. �������� ������ " << std::endl;
                std::cout << "2. ������ ������ �� ������� " << std::endl;
                std::cout << "3. ������������� ������ �� �������" << std::endl;
                std::cout << "4. ���������� ��� ������" << std::endl;
                std::cout << "5. �����" << std::endl;
                std::cout << "0. �����" << std::endl;
                std::cout << "��� �����: ";
                std::cin >> choice;
                system("cls");
                switch (choice) {
                case 1:
                    std::cin >> buffer;
                    keeper.push_back(buffer);
                    break;

                case 2:
                    keeper.remove_id();
                    break;

                case 3:
                    keeper.redact_id();
                    break;
                    break;

                case 4:
                    keeper.displayAll();
                    system("pause");
                    break;

                case 5:
                    keeper.search();
                    system("pause");
                    break;

                case 0:
                    goto A;

                default:
                    std::cout << "�������� ����� �� ������, ����������" << std::endl;
                    system("pause");

                    break;
                }
            }
        }
        case 2: {
            std::string filename = "";
            std::cout << "������� ��� �����: ";
            std::cin >> filename;
            task_2(filename);
            system("pause");
            break;
        }

        case 0: {
            return 0;
        }

        default: {
            std::cout << "�������� ����� �� ������, ����������" << std::endl;
            system("pause");
            break;
        }

        }

    }
}