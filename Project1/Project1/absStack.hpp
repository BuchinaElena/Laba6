#pragma once
#include "wrap.hpp"

template <typename T>
class AbsStack
{
	virtual void Push(T item)=0;//��������
	virtual T Pop()=0;//�������
	virtual Wrap<T>* Peek()=0;//��������(���������)
	virtual int getSize()=0;//������ ������
	virtual void printStack()=0;//������ ���������
};