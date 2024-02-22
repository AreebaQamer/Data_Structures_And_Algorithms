//#include<iostream>
//#include"Queue.h"
//using namespace std;
//void PageReplacement(int memory)
//{
//	Queue<int> one;
//	int page;
//	int pagefault = 0;
//	int pagehit = 0;
//	int size = 0;
//	cout << " enter the page number ";
//	cin >> page;
//	do {
//
//
//
//		if (size < memory)
//		{
//			Queue<int> temp;
//			int flag = 0;
//			while (!one.isEmpty())
//			{
//				if (page == one.getElementAtFront())
//				{
//					temp.enQueue(one.deQueue());
//					flag = 1;
//				}
//				else
//				{
//					temp.enQueue(one.deQueue());
//				}
//			}
//
//			if (flag == 1)
//			{
//				pagehit++;
//			}
//			else
//			{
//				temp.enQueue(page);
//				pagefault++;
//			}
//			cout << endl;
//			cout << " the queue after adding pages is :" << " ";
//			while (!temp.isEmpty())
//			{
//				cout << temp.getElementAtFront() << " ";
//				one.enQueue(temp.deQueue());
//			}
//
//			size++;
//		}
//
//		else
//		{
//
//			Queue<int> temp2;
//			int flag = 0;
//			while (!one.isEmpty())
//			{
//				if (page == one.getElementAtFront())
//				{
//					temp2.enQueue(one.deQueue());
//					flag = 1;
//				}
//				else
//				{
//					temp2.enQueue(one.deQueue());
//				}
//			}
//			if (flag == 1)
//			{
//				pagehit++;
//			}
//			else
//			{
//
//				pagefault++;
//				temp2.deQueue();
//				temp2.enQueue(page);
//
//
//			}
//			cout << endl;
//			cout << " the queue after adding pages  is :" << " ";
//			while (!temp2.isEmpty())
//			{
//				cout << temp2.getElementAtFront() << " ";
//				one.enQueue(temp2.deQueue());
//			}
//
//
//		}
//
//
//
//
//		cout << endl;
//		cout << " enter the page number  & " << "press - 1 to exit ";
//		cin >> page;
//	} while (page != -1);
//	cout << endl;
//	cout << " the total page faults are " << pagefault << endl;
//	cout << endl;
//	cout << " the total page hits are " << pagehit << endl;
//}
//int main()
//{
//	int  size = 0;
//	cout << "enter the size of a memoryy:" << endl;
//	cin >> size;
//	PageReplacement(size);
//}