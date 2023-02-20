#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	// Создаем объект класса List
	List lst;
	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << endl;
	// Определяем длину строки
	int len = strlen(s);
	// Помещаем строку в список
	for(int i = len-1; i >=0; i--)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	//lst.Print();
	// Удаляем два элемента списка
	//lst.Del();
	//lst.Del();
	// Распечатываем содержимое списка
	//lst.Print();
	// Удаляем все элементы списка
	//lst.DelAll();


	// Проверка методов вставки и удаления элемента по номеру позиции
	char data = '$';
	int position = 0;

	while (0 < position < lst.GetCount())
	{
		cout << "INSERT $ TO " << position << " POSITION:\n";
		//вставляем элемент в заданную позицию
		lst.InsertByPosition(data,position);

		// Распечатываем содержимое списка
		lst.Print();

		cout << "REMOVE $ FROM " << position << " POSITION:\n";
		// удаление элемента по заданной позиции
		lst.RemoveByPosition(position);

		// Распечатываем содержимое списка
		lst.Print();

		//cout << "position = " << position << "\n";
		cout << "count = " << lst.GetCount() << "\n";

   		system("pause");
   		system("cls");

		position++;
		if (position > (lst.GetCount() + 1))
			break;
	}

	// Проверка конструктора копирования и перегрузки оператора =
	List lst2=lst;


	// Распечатываем содержимое списка
	cout << "\n New list\n";
	lst2.Print();

	system("pause");
	system("cls");

	// Проверка поиска номера элемента по значению
	while (true) {
		// Распечатываем содержимое списка
		lst.Print();


		char key;
		cout << "\nEnter value to find: ";
		cin >> key;

		if (lst.Find(key) == -1)
			cout << "\nEntered value wasn't found!\n";
		else
			cout << "\nEntered value was found at position: " << lst.Find(key) << "\n";

		system("pause");
		system("cls");
	}



	return 0;
}