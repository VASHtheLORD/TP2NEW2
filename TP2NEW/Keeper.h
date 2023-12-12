#pragma once
#include "note.h"


class Keeper {
public:
    struct container {
        NOTE obj;
        container* next;
    };
    int counter = 0;
    container* first;
    container* last;

    Keeper();
    ~Keeper();

    bool is_empty();// �������� �� �������
    void push_back(NOTE obj); // ���������� ������� � ���������
    void displayAll(); // ����� ���� ��������, ��������������� �� ������ ����� 
    void search();//������� ������
    void remove_id();// �������� �������� �� ��� �������
    void redact_id();//�������������� ��������
};


