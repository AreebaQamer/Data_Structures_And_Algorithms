#include "Stack.h"
#include<iostream>
using namespace std;

template<typename T>
Stack<T>::Stack()
{
	capacity = 0;
	top = 0;
	data = nullptr;
}
template<typename T>
void Stack<T>::push(T val)
{
	if (isFull())
		resize(capacity == 0 ? 1 : capacity * 2);
	data[top++] = val;
}
template<typename T>
int Stack<T>::isFull()
{
	if (top == capacity)
	{
		return true;
	}
	return false;
}
template<typename T>
bool Stack<T>::isEmpty()
{
	return top == 0;
}
template<typename T>
Stack<T>::Stack(const Stack<T>& ref)
{
	if (ref->capacity <= 0)
	{
		data = nullptr;
		capacity = 0;
		return;
	}
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		this - data[i] = ref.data[i];
	}
}

//Assignment Operator
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& ref)
{
	if (ref.data == nullptr)
	{
		data = nullptr;
		capacity = 0;
		//	return;
	}
	if (ref == *this)
	{
		return *this;
	}
	this->~Stack();
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		this->data[i] = ref.data[i];
	}
	return *this;
}
template<typename T>
void Stack<T>::pop()
{

	if (isEmpty())
	{
		exit(0);
	}
	--top;
	if (top > 0 && top == capacity / 4)
	{
		resize(capacity / 2);
	}

}
template<typename T>
T Stack<T>::Top()
{

	return data[top - 1];
}
template<typename T>
Stack<T>::~Stack()
{
	if (!data)
		return;
	delete[]data;
	data = nullptr;
	capacity = 0;
	top = 0;
}