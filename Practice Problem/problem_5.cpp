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
int sizeOfList(Node *&head)
{
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
void middleIndexAndValue(Node *&head)
{
    if (isEmpty(head))
    {
        float size = sizeOfList(head);
        size /= 2;
        size++;
        Node *temp = head;
        int currentIndex = 1;
        while (size != currentIndex)
        {
            currentIndex++;
            temp = temp->next;
        }
        cout << "\nValue : " << temp->value;
    }
    else
        cout << "\nEmpty List";
}
int main()
{
    Node *head;
    middleIndexAndValue(head);
    displayList(head);

    insertValueAtStart(head, 1);
    insertValueAtStart(head, 3);
    insertValueAtStart(head, 5);
    insertValueAtStart(head, 7);

    cout<<sizeOfList(head)<<endl;

    middleIndexAndValue(head);
}