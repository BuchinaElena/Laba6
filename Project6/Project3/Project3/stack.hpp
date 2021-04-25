#pragma once
#include "wrap.hpp"
#include "absStack.hpp"

template <typename T>
class Stack : public AbsStack<T>
{
private:
	Wrap<T>* head;
public:
	Stack();
	Stack(T item);
	Stack(const Stack& other);
	Stack(Stack&& other);
	~Stack();

	void Push(T item) override;//добавить
	T Pop()override;//удалить
	Wrap<T>* Peek()override;//просмотр(заглянуть)
	int getSize()override;//узнать размер
	void printStack()override;//печать построчно
};