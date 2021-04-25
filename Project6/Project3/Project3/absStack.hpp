#pragma once
#include "wrap.hpp"

template <typename T>
class AbsStack
{
	virtual void Push(T item)=0;//добавить
	virtual T Pop()=0;//удалить
	virtual Wrap<T>* Peek()=0;//просмотр(заглянуть)
	virtual int getSize()=0;//узнать размер
	virtual void printStack()=0;//печать построчно
};