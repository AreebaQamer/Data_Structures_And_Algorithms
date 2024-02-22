# include "MEDLL.h"
#include<iostream>
using namespace std;

int main()
{
    XORLinkedList list;
    list.insert_at_head(10);
    list.insert_at_head(20);
    list.insert_at_head(30);
    list.insert_at_head(40);
    cout << "the list after insertion at head is:" << endl;
    list.print_list();
    XORLinkedList list2;
    list2.insert_at_tail(45);
    list2.insert_at_tail(47);
    list2.insert_at_tail(34);
    list2.insert_at_tail(12);
    cout << "the list after insertion at tail is:" << endl;

    list2.print_list();
    //list.delete_from_head();
    //// prints 10 30 40
    list.insertAfter(30, 45);
    list.insertAfter(28, 40);
    list.print_list();
    list.deleteBefore(10);
    list.print_list();
    list.deleteBefore(56);
    list.print_list();
    //list.print_list();
   /* list.deleteAtHead();
    list.print_list();
    list.deleteAtTail();*/
    //list.delete_from_tail();
    //// prints 10 30
    //list.print_list();
    //return 0;
}