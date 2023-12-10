#include "Keeper.h"

Keeper::Keeper() {
	first = nullptr;
	last = nullptr;
	std::cout << "Конструктор объекта класса \"Keeper\" вызван" << std::endl;
}
Keeper::~Keeper() {
	std::cout << "Деструктор объекта типа \"Keeper\" вызван" << std::endl;
}

// Проверка на наличие элементов 
bool Keeper::is_empty() {
	return first == nullptr;
}
// Добавление объекта в контейнер
void Keeper::push_back(NOTE obj) {
	container* buffer = new container;
	buffer->obj = obj;
	if (is_empty()) {
		first = last = buffer;
		buffer->next = nullptr;
		counter++;
		return;
	}
	if (buffer->obj < first->obj) {
		buffer->next = first;
		first = buffer;
		counter++;
		return;
	}
	if (first == last) {
		if (buffer->obj > first->obj) {
			buffer->next = nullptr;
			last = buffer;
			first->next = last;
		}
		else {
			buffer->next = first;
			first = buffer;
		}
		counter++;
		return;
	}
	container* buffer_sort = first;
	while (buffer_sort->next != nullptr) {
		if (buffer->obj > buffer_sort->next->obj) {
			buffer_sort = buffer_sort->next;
		}
		else if (buffer->obj < buffer_sort->next->obj) {
			buffer->next = buffer_sort->next;
			buffer_sort->next = buffer;
			counter++;
			return;
		}
		else {
			buffer->next = buffer_sort->next;
			buffer_sort->next = buffer;
			counter++;
			return;
		}
	}
	buffer->next = nullptr;
	last->next = buffer;
	last = buffer;
	counter++;
}

// Вывод всех объектов
void Keeper::displayAll() {
	if (is_empty()) {
		std::cout << "Контейнер пуст" << std::endl;
		return;
	}
	if (first == last) {
		std::cout << first->obj;
		return;

	}
	container* buffer = first;
	while (buffer != last) {
		std::cout << buffer->obj;
		buffer = buffer->next;
	}
	std::cout << buffer->obj;
}

//Поиск
void Keeper::search() {
	int counter = 0;
	std::string key_word;
	std::cout << "Введите фамилию человека для поиска: ";
	std::cin >> key_word;
	std::cout << std::endl;
	container* buffer = first;
	std::cout << "Вот что нашлось: " << std::endl << std::endl;
	while (buffer->next != nullptr) {
		if (buffer->obj.getLastName() == key_word) {
			std::cout << buffer->obj << std::endl;
			counter++;
		}
		buffer = buffer->next;
	}
	if (buffer->obj.getLastName() == key_word) {
		std::cout << buffer->obj << std::endl;
		counter++;
	}
	if (counter == 0) {
		std::cout << "Ничего не найдено" << std::endl;
	}
}

// Удаление элементов по их индексу
void Keeper::remove_id() {
	int index;
	if (is_empty()) {
		std::cout << "Контейнер пуст" << std::endl;
		system("pause");
		return;
	};
A:
	system("cls");
	container* buffer = first;
	for (int i = 0; i < counter; i++) {
		std::cout << i + 1 << ". " << buffer->obj.getLastName() << std::endl;
		buffer = buffer->next;
	}
	std::cout << "Введите номер человека в списке, которого хотите удалить: ";
	std::cin >> index;
	if (index > counter || index <= 0) {
		std::cout << "Введите цифру из списка пожалуйста";
		goto A;
	}
	if (index == 1) {
		buffer = first;
		first = first->next;
		counter--;
		return;
	}
	if (index == counter) {
		buffer = first;
		while (buffer->next != last) buffer = buffer->next;
		buffer->next = nullptr;
		delete last;
		last = buffer;
		counter--;
		return;
	}
	buffer = first;
	container* buffer_prev = first;
	for (int i = 1; i < index; i++) {
		buffer_prev = buffer;
		buffer = buffer->next;
	}
	buffer_prev->next = buffer->next;
	counter--;
}

void Keeper::redact_id() {
	int index;
	if (is_empty()) {
		std::cout << "Контейнер пуст" << std::endl;
		system("pause");
		return;
	};
A:
	system("cls");
	container* buffer = first;
	container* buff_prev = first;
	NOTE buff;
	for (int i = 0; i < counter; i++) {
		std::cout << i + 1 << ". " << buffer->obj.getLastName() << std::endl;
		buffer = buffer->next;
	}
	std::cout << "Введите номер человека в списке, данные которого нужно отредактировать: ";
	std::cin >> index;
	if (index > counter || index <= 0) {
		std::cout << "Введите цифру из списка пожалуйста";
		goto A;
	}
	if (index == 1) {
		std::cout << "Введите новые значения: " << std::endl;
		first = first->next;
		std::cin >> buff;
		push_back(buff);
		return;
	}
	buffer = first;
	for (int i = 1; i < index; i++) {
		buffer = buffer->next;
	}
	buff_prev->next = buffer->next;
	std::cout << "Введите новые значения: ";
	std::cin >> buff;
	push_back(buff);

	//dsdsds
}