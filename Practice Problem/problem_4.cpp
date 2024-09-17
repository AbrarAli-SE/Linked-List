// Write a C++ program to insert a new node at the end of a Singly Linked List.
// Test Data : Original Linked list : 13 11 9 7 5 3 1 
// Insert a new node at the end of a Singly Linked List : 13 11 9 7 5 3 1 0
#include<iostream>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
    Node(int val)
    {
        value = val;
        next=NULL;
    }
};
void insert(Node *&head,int val)
{
    Node* newNode = new Node(val);
    newNode->next=head;
    head=newNode;
}
void insertAtEnd(Node *&head,int val)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    Node *newNode = new Node(val);
    temp->next=newNode;
    newNode->next=NULL;
}
void display(Node *&head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}