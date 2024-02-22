
#pragma once
#include <iostream>
using namespace std;
template < typename T>
class Stack
{
private:
	T* data;
	int top;
	int capacity;

	void resize(int newCpacity)
	{
		T* temp = new T[newCpacity];
		for (int i = 0; i < top; i++)
		{
			temp[i] = data[i];
		}
		int temptop = top;
		this->~Stack();
		data = temp;
		capacity = newCpacity;
		top = temptop;
	}
public:
	Stack();

	void push(T val);

	int isFull();

	bool isEmpty();


	Stack(const Stack<T>& ref);


	//Assignment Operator
	Stack& operator=(const Stack<T>& ref);

	void pop();

	T Top();

	~Stack();


};
