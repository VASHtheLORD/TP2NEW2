#include "note.h"

//Конструкторы
NOTE::NOTE(std::string fname, std::string lname, long long num, int* bth) {
    first_name = fname;
    last_name = lname;
    telephone_number = num;
    for (int i = 0; i < 3; i++) {
        birthday[i] = bth[i];
    }
}
NOTE::NOTE(const NOTE& obj) {
    first_name = obj.first_name;
    last_name = obj.last_name;
    telephone_number = obj.telephone_number;
    for (int i = 0; i < 3; i++) {
        birthday[i] = obj.birthday[i];
    }
}
NOTE::NOTE() {
    first_name = "";
    last_name = "";
    telephone_number = 0;
    birthday[0] = 0;
    birthday[1] = 0;
    birthday[2] = 0;
    std::cout << "Конструктор объекта класса \"NOTE\" вызван" << std::endl;
}

//Деструктор
NOTE::~NOTE() {
    std::cout << "Деструктор объекта типа \"NOTE\" вызван" << std::endl;
}

//Дружественная функция перегрузки оператора вывода
std::ostream& operator << (std::ostream& os, const NOTE& note) {
    os << "Имя: " << note.first_name << std::endl
        << "Фамилия: " << note.last_name << std::endl
        << "Дата рождения: ";
    for (int i = 0; i < 2; i++) {
        os << note.birthday[i] << ".";
    }
    os << note.birthday[2] << std::endl << "Номер телефона " << note.telephone_number << std::endl << std::endl;
    return os;
}



//Дружественная функция перегрузки оператора ввода
std::istream& operator>> (std::istream& in, NOTE& note) {
    std::string str1;
    std::string str2;
    long long num;
    int buff_array[3];
    std::cout << "Введите Имя: ";
    in >> str1;
    std::cout << "Введите Фамилию: ";
    in >> str2;
    std::cout << "Введите номер телефона(11 знаков): ";
    in >> num;
    std::cout << "Введите день рождения: ";
    in >> buff_array[0];
    std::cout << "Введите месяц рождения: ";
    in >> buff_array[1];
    std::cout << "Введите год рождения: ";
    in >> buff_array[2];

    note.push(str1, str2, num, buff_array);

    return in;
}

//Дружественные функции для сравнения двух объектов для сортировки
bool operator<(const NOTE& a, const NOTE& b) {
    int buff_a = a.telephone_number / 100000000;
    int buff_b = b.telephone_number / 100000000;
    return buff_a < buff_b;
}
bool operator>(const NOTE& a, const NOTE& b) {
    int buff_a = a.telephone_number / 100000000;
    int buff_b = b.telephone_number / 100000000;
    return buff_a > buff_b;
}


//Метод для измененения полей класса
void NOTE::push(std::string fname, std::string lname, long long num, int* buff_array) {
    first_name = fname;
    last_name = lname;
    telephone_number = num;
    for (int i = 0; i < 3; i++) {
        birthday[i] = buff_array[i];
    }
}

//Метоы для доступа к полям класса
std::string NOTE::getFirstName() { return first_name; }
std::string NOTE::getLastName() { return last_name; }
long long NOTE::getTelefoneNumber() { return telephone_number; }
int NOTE::getBirthday(int i) { return birthday[i]; }

