#pragma once
#include <stdlib.h>

// Элемент данных
struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element * Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element * Head;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();

	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится головным)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();

	// удаление всех элементов списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();

	// Вставка элемента в заданную позицию
	void InsertByPosition(char data, int position);

	// удаление элемента по заданной позиции
	void RemoveByPosition(int position);

	// поиск заданного элемента по ключу
	int Find(char key);

	//конструктор копирования
	List(const List& obj);

	// перегруженный оператор =
	List & operator = (const List & obj);

};
