#include<iostream>
using namespace std;
#include "Stack.h"
# include "Stack.cpp"
#include<string>
void ReversePolishCalculator()
{
	Stack<int>oper;
	int UserChoice = 0;
	char sign;
	int noOfOperands = 0;
	int flag = 0;
	cout << "ENTER THE USER CHOICES:" << endl;
	cout << "PRESS 1  IF YOU WANT TO OPERAND IN STACK " << endl;
	cout << " PRESS 2 IF YOU WANT TO PERFORM OPERATIONS ON OPERAND:" << endl;
	cout << "ENTER - 1 FOR EXIT : " << endl;
	cin >> UserChoice;
	do
	{
		if (UserChoice == 1)
		{
			string op;
			cout << "Enter the operand:" << endl;
			cin >> op;
			for (int i = 0; i < op.length(); i++)
			{
				if (!isdigit(op[i]))
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				cout << "# It is an invalid input,We cannot do anything with it:" << endl;
			}
			else
			{
				oper.push(stoi(op));
				noOfOperands++;
			}
		}
		else if (UserChoice == 2)
		{
			if (noOfOperands >= 2)
			{

				cout << "Enter the operator:" << endl;
				cin >> sign;
				if (sign == '+')
				{
					int val1 = oper.Top();
					oper.pop();
					noOfOperands--;
					int val2 = oper.Top();
					oper.pop();
					noOfOperands--;
					oper.push(val2 + val1);
					noOfOperands++;
				}
				else if (sign == '-')
				{
					int val1 = oper.Top();
					oper.pop();
					noOfOperands--;
					int val2 = oper.Top();
					oper.pop();
					noOfOperands--;
					oper.push(val2 - val1);
					noOfOperands++;
				}
				else if (sign == '*')
				{
					int val1 = oper.Top();
					oper.pop();
					noOfOperands--;
					int val2 = oper.Top();
					oper.pop();
					noOfOperands--;
					oper.push(val2 * val1);
					noOfOperands++;
				}
				else if (sign == '%')
				{
					int val1 = oper.Top();
					oper.pop();
					noOfOperands--;
					int val2 = oper.Top();
					oper.pop();
					noOfOperands--;
					oper.push(val2 % val1);
					noOfOperands++;
				}
				else if (sign == '/')
				{
					int val1 = oper.Top();
					oper.pop();
					noOfOperands--;
					int val2 = oper.Top();
					oper.pop();
					noOfOperands--;
					if (val2 != 0)
					{
						oper.push(val2 / val1);
						noOfOperands++;
					}
					else
					{
						cout << "# Divison cannot be done by 0 :" << endl;
						oper.push(val1);
						noOfOperands++;
						oper.push(val2);
						noOfOperands++;
					}
				}
				else if (sign == '^')
				{
					cout << "The top most element is:" << oper.Top() << endl;
				}
				else if (sign == '?')
				{
					Stack<int>s;
					while (!oper.isEmpty())
					{
						int val = oper.Top();
						cout << endl << val;
						s.push(val);
						oper.pop();
					}
				}
			}

			else
			{
				cout << "# There should be two operands:" << endl;
			}
		}
		cout << endl;
		cout << "PRESS 1  IF YOU WANT TO ADD OPERAND IN STACK " << endl;
		cout << " PRESS 2 IF YOU WANT TO PERFORM OPERATIONS ON OPERAND:" << endl;
		cout << "ENTER - 1 FOR EXIT : " << endl;
		cin >> UserChoice;
	} while (UserChoice != -1);
	cout << "THE ANSWER OF YOUR CALCULATOR IS:" << oper.Top() << endl;
}
int main()
{

	ReversePolishCalculator();
}
	

//#include "stack.cpp"
//#include <iostream>
//#include<string>
//using namespace std;
//int RPNcalculator()
//{
//	int choice;
//	int numberofoperands = 0;
//	Stack<int> s;
//	cout << "  ENETER 1 IF YOU WANT TO ADD OPERAND " << endl;
//	cout << "ENTER 2 IF  YOU WANT TO PLACE ANY OPERATOR " << endl;
//	cout << " ENTER 3 IF YOU WANT TO EXIT " << endl;
//	cin >> choice;
//	do {
//
//		if (choice == 1)
//		{
//			string operands;
//			int flag = 0;
//			cout << " enter operand " << endl;
//			cin >> operands;
//			for (int i = 0; i < operands.size(); i++)
//			{
//				if (!isdigit(operands[i]))
//				{
//					flag = 1;
//				}
//			}
//			if (flag == 1)
//			{
//				cout << "# wrong output  you should only add integers " << endl;
//			}
//			else {
//				s.push(stoi(operands));
//				numberofoperands++;
//			}
//
//
//		}
//		else if (choice == 2)
//		{
//
//			if (numberofoperands >= 2)
//			{
//				char operators;
//
//				cout << " enter operator " << endl;
//				cin >> operators;
//				if (operators == '+')
//				{
//					int val = s.Top();
//					s.pop();
//					numberofoperands--;
//					int val2 = s.Top();
//					s.pop();
//					numberofoperands--;
//					int answer = val + val2;
//					s.push(answer);
//					numberofoperands++;
//
//				}
//				else if (operators == '-')
//				{
//					int val = s.Top();
//					s.pop();
//					numberofoperands--;
//					int val2 = s.Top();
//					s.pop();
//					numberofoperands--;
//					int answer = val2 - val;
//					s.push(answer);
//					numberofoperands++;
//				}
//				else if (operators == '*')
//				{
//					int val = s.Top();
//					s.pop();
//					numberofoperands--;
//					int val2 = s.Top();
//					s.pop();
//					numberofoperands--;
//					int answer = val * val2;
//					s.push(answer);
//					numberofoperands++;
//				}
//				else if (operators == '/')
//				{
//					int val = s.Top();
//					s.pop();
//					numberofoperands--;
//					int val2 = s.Top();
//					s.pop();
//					numberofoperands--;
//					if (val2 != 0)
//					{
//						int answer = val2 / val;
//						s.push(answer);
//						numberofoperands++;
//					}
//					else {
//						cout << " #we cant divide a number by zero  ";
//						s.push(val);
//						numberofoperands++;
//						s.push(val2);
//						numberofoperands++;
//					}
//
//				}
//				else if (operators == '?')
//				{
//					Stack<int> tempStack;
//
//
//					while (!s.isEmpty())
//					{
//						int val = s.Top();
//						cout << endl << val;
//						tempStack.push(val);
//						s.pop();
//					}
//
//
//					while (!tempStack.isEmpty())
//					{
//						s.push(tempStack.Top());
//						tempStack.pop();
//					}
//
//
//
//				}
//				else if (operators == '^')
//				{
//					cout << endl << " the last enter digit is " << s.Top();
//				}
//
//			}
//			else
//			{
//				cout << " #there should be must two operands " << endl;
//			}
//
//
//		}
//
//		cout << endl;
//		cout << "ENETER 1 IF YOU WANT TO ADD OPERAND " << endl;
//		cout << "ENTER 2 IF  YOU WANT TO PLACE ANY OPERATOR " << endl;
//		cout << "ENTER 3 IF YOU WANT TO EXIT " << endl;
//		cin >> choice;
//
//	} while (choice != 3);
//	return s.Top();
//
//}
//int main()
//{
//	cout << " the  answer of your calulation is " << RPNcalculator();
//}