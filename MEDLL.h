#pragma once
#include<iostream>
using namespace std;
struct Node 
{
    int data;
    // XOR of next and prev
    Node* npx;
};
class XORLinkedList 
{
private:
    Node* head;
    Node* tail;
    // XOR function for Node pointers
    Node* XOR(Node* a, Node* b);

public:
    // Constructor to initialize an empty list
    XORLinkedList();
    // Insert a node at the head of the list
    void insert_at_head(int data);
    // Insert a node at the tail of the list
    void insert_at_tail(int data);
    // Delete a node from the head of the list
    void deleteAtHead();
    // Delete a node from the tail of the list
    void deleteAtTail();
    // Print the elements of the list
    void print_list();
    // insert  a node after
    void insertAfter(int val,int key);
    void deleteBefore(int val);
};
XORLinkedList::XORLinkedList()
{
    head = tail = nullptr; // Initialize head and tail to
    // nullptr for an empty list
}
Node* XORLinkedList::XOR(Node* a, Node* b)
{
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));

 
}

void XORLinkedList::insert_at_head(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->npx = XOR(nullptr, head);

    if (head) 
    {
        head->npx
            = XOR(new_node, XOR(head->npx, nullptr));
    }
    else {
        // If the list was empty, the new
        // node is both the head and the
        // tail
        tail = new_node;
    }
    // Update the head to the new node
    head = new_node;
}

void XORLinkedList::insert_at_tail(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->npx = XOR(tail, nullptr);

    if (tail) {
        tail->npx = XOR(XOR(tail->npx, nullptr), new_node);
    }
    else {
        // If the list was empty, the new
        // node is both the head and the
        // tail
        head = new_node;
    }
    // Update the tail to the new node
    tail = new_node;
}
void XORLinkedList:: deleteAtHead() 
{
    if (head == nullptr)
    {
        std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
    
    }


    if (head->npx != nullptr) {
        Node* newHead = XOR(nullptr, head->npx);
        if (newHead != nullptr) {
            newHead->npx= XOR(newHead->npx, head);
        }
        delete head;
        head = newHead;
    }
    else {
        delete head;
        head = nullptr;
    }
}


void XORLinkedList::deleteAtTail() 
{
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next;

    while (current->npx != prev) {
        next = XOR(prev, current->npx);
        prev = current;
        current = next;
    }


    if (prev != nullptr) {
        prev->npx= XOR(prev->npx, current);
    }

    delete current;
}

void  XORLinkedList:: insertAfter(int val, int key) 
{
    Node* newNode = new Node();
    newNode->data = val;
    if (head == nullptr) 
    {
        cout << "List is empty. Cannot perform insertAfter operation." << endl;
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (curr != nullptr) {
        if (prev == nullptr) {
            next = XOR(curr->npx, nullptr);
        }
        else {
            next = XOR(prev, curr->npx);
        }

        if (curr->data == key) {
            newNode->npx = XOR(curr, next);

            if (next != nullptr) {
                Node* nextNext = XOR(curr, XOR(next->npx, prev)); // Calculate next's next node
                next->npx = XOR(newNode, nextNext);
            }
            else {
                tail = newNode;
            }

            curr->npx = XOR(prev, newNode);

            cout << "Inserted " << val << " after " << key << endl;
            return;
        }

        prev = curr;
        curr = next;
    }

    cout << "Key " << key << " not found. Insertion failed." << endl;
}
void XORLinkedList::print_list()
{
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        std::cout << current->data << " ";
        Node* next = XOR(prev, current->npx);
        prev = current;
        current = next;
    }
    std::cout << std::endl;
}

int main()
{
    XORLinkedList list;
    list.insert_at_head(10);
    list.insert_at_head(20);
    list.insert_at_head(30);
    list.insert_at_head(40);
    cout << "the list after insertion at head is:" << endl;
    // prints 20 10 30 40
    list.print_list();
    // prints 20 10 30 40
    list.print_list();
    //list.delete_from_head();
    //// prints 10 30 40
    list.insertAfter(30,45);
    //list.print_list();
   /* list.deleteAtHead();
    list.print_list();
    list.deleteAtTail();*/
    list.print_list();
    //list.delete_from_tail();
    //// prints 10 30
    //list.print_list();
    //return 0;
}
