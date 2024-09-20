// 6. Write a C++ program to find the middle element of a given Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Middle element of the said list:
// 3
// Original list:
// 9 7 5 3 1
// Middle element of the said list:
// 5
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
bool isEmpty(Node *&head)
{
    if (head != NULL)
        return true;
    return false;
}
void displayList(Node *&head)
{
    if (isEmpty(head))
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else
        cout << "\nEmpty List";
}
void insertValueAtStart(Node *&head, int Value)
{
    Node *newNode = new Node(Value);
    newNode->next = head;
    head = newNode;
}
void middleIndexAndValue