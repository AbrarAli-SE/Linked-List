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
void insert(Node *&head,int val)
{
    Node *newNode = new Node(val);
    newNode->next=head;
    head=newNode;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    free(temp);
    cout << endl;
}
void reverse(Node *&head)
{
    if(head==NULL)
    return;
    reverse(head->next);
    cout<<head->value<<" ";
}
int main()
{
    Node *head = NULL;
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value " << i + 1 << " : ";
        int val;
        cin >> val;
        insert(head, val);
    }
    cout << "\nOrignal List : ";
    display(head);

    cout << "\nReverse List : ";
    reverse(head);
}
//done