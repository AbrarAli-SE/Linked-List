// 8. Write a C++ program to get Nth node in a given Singly Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Position: 1
// Value: 7
// Position: 2
// Value: 5
// Position: 3
// Value: 3
// Position: 4
// Value: 1
#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};
void insertValueAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void display(Node *head)
{
    Node *temp = head;
    int position=1;
    while (temp->next!= NULL)
    {
        cout << "\nPosition : "<<position<<"\nValue : " << temp->value<<endl;
        temp = temp->next;
        position++;
    }

    cout << endl<<position<<endl;
}
int main()
{
    Node *head = NULL;

    insertValueAtHead(head, 1);
    insertValueAtHead(head, 3);
    insertValueAtHead(head, 5);
    insertValueAtHead(head, 7);
    display(head);
}