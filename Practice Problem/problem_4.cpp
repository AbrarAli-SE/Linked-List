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
    while(temp->next!=NULL)
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
int main()
{
    Node *head = NULL;
    int n = 7;
    int arr[7]={1,3,5,7,9,11,13};//for automatic inputs
    for (int i = 0; i < n; i++)
    {
        // cout << "Enter Value " << i + 1 << " : ";
        // int val;
        // cin >> val;
        insert(head, arr[i]);
    }
    cout << "\nGiven List : ";
    display(head);
    cout << "Enter a Value to insert at end : ";
    int val;
    cin >> val;
    insertAtEnd(head,val);
    cout << "\nUpdate List: ";
    display(head);
}