// Write a C++ program to create a singly linked list of n
// nodes and display it in reverse order.
// Test Data : Original Linked list : 11 9 7 5 3 1
// Reverse Linked list : 1 3 5 7 9 11
#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node() {}
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}