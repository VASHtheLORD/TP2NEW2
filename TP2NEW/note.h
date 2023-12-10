#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

class NOTE {
private:
	std::string first_name;
	std::string last_name;
	long long telephone_number;
	int birthday[3];
public:
	//������������
	NOTE(std::string fname, std::string lname, long long num, int* bth);
	NOTE(const NOTE& obj);
	NOTE();

	~NOTE();

	//������������� ������� ���������� ��������� ������
	friend std::ostream& operator << (std::ostream& os, const NOTE& aeroflot);

	//������������� ������� ���������� ��������� �����
	friend std::istream& operator >> (std::istream& in, NOTE& aeroflot);

	//������������� ������� ��� ��������� ���� �������� ��� ����������
	friend bool operator<(const NOTE& a, const NOTE& b);
	friend bool operator>(const NOTE& a, const NOTE& b);

	//����� ��� ����������� ����� ������
	void push(std::string fname, std::string lname, long long num, int* buff_array);

	//����� ��� ������� � ����� ������
	std::string getFirstName();
	std::string getLastName();
	long long getTelefoneNumber();
	int getBirthday(int i);
};

