#include <iostream>
#include "stack.hpp"
#include "wrap.hpp"
#include "stack.cpp"
#include "wrap.cpp"

using namespace std;

int main()
{
	Stack<int> s;

	for (int i = 0; i < 4; i++)
	{
		cout << i << endl;
		s.Push(i);
	}

	s.printStack();

	cout << endl;
	cout << "POPPED--------------------------------" << endl;
	cout << endl;

	s.Pop();
	s.printStack();

	system("pause");
}