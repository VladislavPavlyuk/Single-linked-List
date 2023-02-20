#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	// Изначально список пуст
	Head = nullptr;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count - 1;
}

void List::Add(char data)
{
	// создание нового элемента
	Element * temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент - головной элемент списка
	temp->Next = Head;

	// новый элемент становится головным элементом списка
	Head = temp;

	Count++;
}

void List::Del()
{
	if(Head)
	{
		// запоминаем адрес головного элемента
		Element * temp = Head->Next;

		// удаляем бывший головной элемент
		delete Head;

		// перебрасываем голову на следующий элемент
		Head = temp;
		Count--;
	}
}

void List::DelAll()
{
	// Пока еще есть элементы
	while(Head != nullptr)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element * temp = Head;
	if (temp == nullptr)
	{
		cout << "List is empty!";
		return;
	}
	// Пока еще есть элементы
	while(temp != 0)
	{
		// Выводим данные
		cout << temp->data;
		// Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << endl;
}

// Функция создания новых элементов
Element* getElement(int data)
{
	Element* newElement = new Element();
	newElement->data = data;
	newElement->Next = NULL;
	return newElement;
}

void List::InsertByPosition(char data, int position)
{

	if (Head == nullptr)
	{
		cout << "List is empty!\n";
		return;
	}

	if ((position < 1)||(position > GetCount()))
		{
			cout << "Wrong position!\n";
			return;
		}

	if (position == 1)
	{
		Add(data);
	}

	else
	{
		// запоминаем адрес головного элемента
		Element *temp = Head;

		// создание нового элемента
		Element* N = getElement(data);

		//траверс до текщего элемента
			while (--position > 1)
				{
					temp = temp -> Next;
				}

			//присваеваем новому элементу адрес следующего
			N->Next = temp->Next;

			// присваеваем текущему элементу адрес нового
			temp->Next = N;

			Count++;
	}
}

void List::RemoveByPosition(int position)
 {
	// запоминаем адрес головного элемента
	Element* temp = Head;
	Element* prev = Head;

	if (temp == nullptr)
	{
		cout << "List is empty!\n";
		return;
	}

	if ((position <= 0) || (position > GetCount()))
	{
		cout << "Wrong position!\n";
		return;
	}

	for (int i = 0; i < position; i++)
	{
		if (i == 0 && position == 1)
		{
			Head = Head->Next;
			free(temp);
		}

		else
		{
			if (i == position - 1 && temp)
			{
				prev->Next = temp->Next;
				free(temp);
			}
			else
			{
				prev = temp;
				if (prev == NULL)
					break;
				temp = temp->Next;
			}
		}
	}
	Count--;

}

int List::Find(char key)
{
	// запоминаем адрес головного элемента
	Element* temp = Head;

	int position = 0;
	bool exist = false;

	if (temp == nullptr)
	{
		cout << "List is empty!";
		return -1;
	}

	// Пока еще есть элементы
	while (temp != 0)
	{
		position++;
		// Выводим данные
		if (temp->data == key)
		{
			exist = true;
			return position;
		}

		// Переходим на следующий элемент
		temp = temp->Next;
	}
	if (exist == false)
		return -1;

}


List::List(const List& obj)
{
	Head = new Element();

	Element* oldPtr = obj.Head;

	Element* newPtr = Head;

	while (oldPtr != nullptr)
	{
		newPtr->data = oldPtr->data;

		if (oldPtr->Next != nullptr)
		{
			newPtr->Next = new Element();

			newPtr = newPtr->Next;
		}
		oldPtr = oldPtr->Next;
	}
}

List& List::operator= (const List& obj)
{
	if (this == &obj)

		return *this;

	DelAll();

	Element* newElement = new Element;

	newElement->data = obj.Head -> data;

	newElement->Next = NULL;

	Head = newElement;

	Element* curr = obj.Head;
	while (curr->Next != NULL)
	{
		curr = curr->Next;

		newElement->Next = new Element;

		newElement = newElement->Next;

		newElement->data = curr->data;

		newElement->Next = NULL;
	}

	  return *this;
}
