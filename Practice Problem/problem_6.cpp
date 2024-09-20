// Write a C++ program to insert a new node at the middle of a given Singly Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Singly Linked List: after insert 9 in the middle of the said list-
// 7 5 9 3 1
// Singly Linked List: after insert 11 in the middle of the said list-
// 7 5 9 11 3 1
// Singly Linked List: after insert 13 in the middle of the said list-
// 7 5 9 13 11 3 1
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
void insertValueAtSpacificPoint(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertValueAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int currentPosition=0;
    while(currentPosition!=pos-1)
    {
        temp=temp->next;
        currentPosition++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
int middleIndex(Node *&head)
{
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    size /= 2;
    size++;
    return size;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->value;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;

    insertValueAtHead(head, 1);
    insertValueAtHead(head, 3);
    insertValueAtHead(head, 5);
    insertValueAtHead(head, 7);
    display(head);

    insertValueAtSpacificPoint(head, 9,middleIndex(head));
    display(head);

    insertValueAtSpacificPoint(head, 11, middleIndex(head));
    display(head);

    insertValueAtSpacificPoint(head, 13, middleIndex(head));
    display(head);
}