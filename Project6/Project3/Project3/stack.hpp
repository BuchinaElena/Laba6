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

	void Push(T item) override;//��������
	T Pop()override;//�������
	Wrap<T>* Peek()override;//��������(���������)
	int getSize()override;//������ ������
	void printStack()override;//������ ���������
};