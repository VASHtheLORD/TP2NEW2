#include "note.h"

//������������
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
    std::cout << "����������� ������� ������ \"NOTE\" ������" << std::endl;
}

//����������
NOTE::~NOTE() {
    std::cout << "���������� ������� ���� \"NOTE\" ������" << std::endl;
}

//������������� ������� ���������� ��������� ������
std::ostream& operator << (std::ostream& os, const NOTE& note) {
    os << "���: " << note.first_name << std::endl
        << "�������: " << note.last_name << std::endl
        << "���� ��������: ";
    for (int i = 0; i < 2; i++) {
        os << note.birthday[i] << ".";
    }
    os << note.birthday[2] << std::endl << "����� �������� " << note.telephone_number << std::endl << std::endl;
    return os;
}



//������������� ������� ���������� ��������� �����
std::istream& operator>> (std::istream& in, NOTE& note) {
    std::string str1;
    std::string str2;
    long long num;
    int buff_array[3];
    std::cout << "������� ���: ";
    in >> str1;
    std::cout << "������� �������: ";
    in >> str2;
    std::cout << "������� ����� ��������(11 ������): ";
    in >> num;
    std::cout << "������� ���� ��������: ";
    in >> buff_array[0];
    std::cout << "������� ����� ��������: ";
    in >> buff_array[1];
    std::cout << "������� ��� ��������: ";
    in >> buff_array[2];

    note.push(str1, str2, num, buff_array);

    return in;
}

//������������� ������� ��� ��������� ���� �������� ��� ����������
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


//����� ��� ����������� ����� ������
void NOTE::push(std::string fname, std::string lname, long long num, int* buff_array) {
    first_name = fname;
    last_name = lname;
    telephone_number = num;
    for (int i = 0; i < 3; i++) {
        birthday[i] = buff_array[i];
    }
}

//����� ��� ������� � ����� ������
std::string NOTE::getFirstName() { return first_name; }
std::string NOTE::getLastName() { return last_name; }
long long NOTE::getTelefoneNumber() { return telephone_number; }
int NOTE::getBirthday(int i) { return birthday[i]; }

