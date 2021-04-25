#include <stdio.h>
#include "stack.hpp"
#include "wrap.hpp"
#include <iostream>

using namespace std;

template <typename T>
Stack<T>::Stack()
{
	head = NULL;
}
template <typename T>
Stack<T>::Stack(T item)
{
	Wrap<T> x = Wrap<T>(item);
	head = &x;
}

template <typename T>
Stack<T>::Stack(const Stack& other)
{
	if (other.head == NULL)
		head = NULL;
	else if (other.head.getNext() == NULL)
	{
		Wrap<T>* wrap(other.head.getData());
		head = wrap;
	}
	else
	{
		Wrap<T>* wrap(other.head.getData());
		head = wrap;
		Wrap<T>* x = other.head;
		while (other.head != x.getNext())
		{
			x = x.getNext();
			Wrap<T> wrap(x.getData());
			Push(x);
		}
	}
}

template <typename T>
Stack<T>::Stack(Stack&& other)
{
	head = other.head;
	other.head = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
	while (head != NULL)
	{
		Pop();
	}
}

template <typename T>
void Stack<T>::Push(T item)
{
	Wrap<T>* x = new Wrap<T>(item);


	if (head == NULL)
	{
		head = x;
	}
	else if (head->getNext() == NULL)
	{

		head->setNext(x);
		head->setPrev(x);
		x->setNext(head);
		x->setPrev(head);
		head = x;
	}
	else
	{
		x->setPrev(head->getPrev());
		head->getPrev()->setNext(x);
		x->setNext(head);
		head->setPrev(x);
		head = x;
	}
}

template <typename T>
T Stack<T>::Pop()
{
	Wrap<T>* item = head;
	T data = item->getData();
	if (head == NULL)
		;
	else if (head->getNext() == NULL)
		delete[] head;
	else if (head->getNext()->getNext() == NULL)
	{
		head->getNext()->setNext(NULL);
		head->getPrev()->setPrev(NULL);
		delete[] head;
		head = head->getNext();
	}
	else
	{
		head->getPrev()->setNext(head->getNext());
		head->getNext()->setPrev(head->getPrev());
		
		head = head->getNext();
		delete item;
	}
	return data;
}

template <typename T>
Wrap<T>* Stack<T>::Peek()
{
	if (head != NULL)
		return head;
	else
		return NULL;
}

template <typename T>
int Stack<T>::getSize() 
{ 
	if (head == NULL)
		return 0;
	else if (head->getNext() == NULL)
		return 1;
	else
	{
		Wrap<T>* x = head->getNext();
		int i = 2;
		while (head != x->getNext())
		{
			x = x->getNext();
			i++;
		}
		return i;
	} 
}

template <typename T>
void Stack<T>::printStack()
{
	cout << "Stack size: " << getSize() << endl;
	cout << endl;
	if (head == NULL)
		;
	else if (head->getNext() == NULL)
		cout << "Current: " << head->getData() << endl;
	else
	{
		Wrap<T>* x = head;
		cout << "Current: " << x->getData() << endl;
		cout << "Previous: " << x->getPrev()->getData() << endl;
		cout << "Next: " << x->getNext()->getData() << endl;
		while (head != x->getNext())
		{
			x = x->getNext();
			cout <<""<< endl;
			cout << "Current: " << x->getData() << endl;
			cout << "Previous: " << x->getPrev()->getData() << endl;
			cout << "Next: " << x->getNext()->getData() << endl;
		}
	}
	

}
