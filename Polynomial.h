//#pragma once
//#pragma once
//#define POLYNOMIAL_H
//#include<iostream>
//using namespace std;
//class polynomial;
//class term {
//	friend polynomial;
//private:
//	int coefficient;
//	int power;
//	term* next;
//};
//class polynomial {
//private:
//	term* head;
//public:
//	polynomial()
//	{
//		head = nullptr;
//	}
//	void addTerm(int c, int p)
//	{
//		term* newNode = new term;
//		newNode->coefficient = c;
//		newNode->power = p;
//		if (!head)
//		{
//			newNode->coefficient = c;
//			newNode->power = p;
//			newNode->next = nullptr;
//			head = newNode;
//		}
//		else {
//			if (head->next == nullptr)
//			{
//				if (newNode->power > head->power)
//				{
//					term* temp = head;
//					head = newNode;
//					head->next = temp;
//					temp->next = nullptr;
//				}
//				if (newNode->power < head->power)
//				{
//					newNode->coefficient = c;
//					newNode->power = p;
//					head->next = newNode;
//					newNode->next = nullptr;
//				}
//			}
//			else if (head->next != nullptr && head)
//			{
//				bool found = false;
//				term* current;
//				term* temp = nullptr;
//				current = head;
//				while (!(newNode->power > current->power))
//				{
//					temp = current;
//					current = current->next;
//					if (current->power > newNode->power && current->next == nullptr)
//					{
//						found = true;
//						break;
//					}
//				}
//				if (!found)
//				{
//					newNode->next = current;
//					temp->next = newNode;
//				}
//				else {
//					current->next = newNode;
//					newNode->next = nullptr;
//				}
//			}
//			else if ((head->next != nullptr && head) && newNode->power > head->power)
//			{
//				newNode->next = head;
//				head = newNode;
//			}
//		}
//	}
//	void display()
//	{
//		term* current = head;
//		do
//		{
//			cout << current->coefficient << "x" << "^" << current->power << " ";
//			if (current->next != nullptr)
//			{
//				if (current->next->coefficient > 0)
//					cout << "+";
//			}
//			current = current->next;
//
//		} while (current != nullptr);
//		//cout << current->coefficient << "x" << current->power << " ";
//	}
//	int getDegree()
//	{
//		return head->power;
//	}
//	int getCoefficient(int p)
//	{
//		term* current = head;
//		while (!(current->power == p))
//		{
//			current = current->next;
//			if (current->power != p && current->next == nullptr)
//			{
//				cout << "no coefficient found";
//				return -1;
//				break;
//			}
//		}
//		return current->coefficient;
//	}
//	void evaluate(int val)
//	{
//		int eva = 0;
//		term* current = head;
//		while (current != nullptr)
//		{
//			eva = eva + current->coefficient * (pow(val, current->power));
//			current = current->next;
//		}
//		cout << eva;
//	}
//	void clear()
//	{
//		term* current = head;
//		while (current != nullptr)
//		{
//			current->coefficient = 0;
//			current = current->next;
//		}
//	}
//	void addToCoefficient(int c, int p)
//	{
//		term* current = head;
//		while (!(current->power == p))
//		{
//			current = current->next;
//			if (!(current->power == p) && (current->next == nullptr))
//			{
//				cout << "error in coefficient or power, input values not found " << endl;
//				break;
//			}
//		}
//		current->coefficient = current->coefficient + c;
//	}
//	void Derivative()
//	{
//		term* current = head;
//		while (current != nullptr)
//		{
//			if (current->power != 0 && current->power != 1)
//			{
//				cout << current->coefficient * current->power << "X^" << current->power - 1;
//			}
//			if (current->power == 1)
//			{
//				cout << current->coefficient << " ";
//			}
//
//			if (current->next != nullptr)
//			{
//				if (current->next->coefficient > 0 && current->next->power > 1)
//					cout << "+";
//			}
//			current = current->next;
//		}
//	}
//
//	polynomial operator+(polynomial& p)
//	{
//		polynomial result;
//		term* p1 = head;
//		term* p2 = p.head;
//		term* p3 = nullptr;
//		term* prev = nullptr;
//
//		while (p1 != nullptr && p2 != nullptr)
//		{
//			term* newTerm = new term;
//			if (p1->power == p2->power)
//			{
//				newTerm->coefficient = p1->coefficient + p2->coefficient;
//				newTerm->power = p1->power;
//				p1 = p1->next;
//				p2 = p2->next;
//			}
//			else if (p1->power > p2->power)
//			{
//				newTerm->coefficient = p1->coefficient;
//				newTerm->power = p1->power;
//				p1 = p1->next;
//			}
//			else
//			{
//				newTerm->coefficient = p2->coefficient;
//				newTerm->power = p2->power;
//				p2 = p2->next;
//			}
//
//			if (prev != nullptr)
//			{
//				prev->next = newTerm;
//			}
//			else
//			{
//				result.head = newTerm;
//			}
//			prev = newTerm;
//		}
//
//		if (p1 != nullptr)
//		{
//			prev->next = p1;
//		}
//		else if (p2 != nullptr)
//		{
//			prev->next = p2;
//		}
//
//		return result;
//	}
//	polynomial operator-(polynomial& p)
//	{
//		polynomial result;
//		term* p1 = head;
//		term* p2 = p.head;
//		term* p3 = nullptr;
//		term* prev = nullptr;
//
//		while (p1 != nullptr && p2 != nullptr)
//		{
//			term* newTerm = new term;
//			if (p1->power == p2->power)
//			{
//				newTerm->coefficient = p1->coefficient - p2->coefficient;
//				newTerm->power = p1->power;
//				p1 = p1->next;
//				p2 = p2->next;
//			}
//			else if (p1->power > p2->power)
//			{
//				newTerm->coefficient = p1->coefficient;
//				newTerm->power = p1->power;
//				p1 = p1->next;
//			}
//			else
//			{
//				newTerm->coefficient = p2->coefficient;
//				newTerm->power = p2->power;
//				p2 = p2->next;
//			}
//
//			if (prev != nullptr)
//			{
//				prev->next = newTerm;
//			}
//			else
//			{
//				result.head = newTerm;
//			}
//			prev = newTerm;
//		}
//
//		if (p1 != nullptr)
//		{
//			prev->next = p1;
//		}
//		else if (p2 != nullptr)
//		{
//			prev->next = p2;
//		}
//
//		return result;
//	}
//
//};
