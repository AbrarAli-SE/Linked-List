// 1. 
//Write a C++ program to create and display a Singly Linked List.
//Test Data : The list contains the data entered : 11 9 7 5 3 1
//Solution
#include<iostream>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
    Node()
    {
        next=NULL;
    }
    Node(int val)
    {
        value=val;
        next=NULL;
    }
};
void insert(Node* &head,int val)
{
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;

}
void display(Node* &head){
    Node* temp=head;
    while(temp!= NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* head =NULL;
    int n=6;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Value "<<i+1<<" : ";
        int val;
        cin>>val;
        insert(head,val);
    }
    cout<<"\nInputs are : ";
    display(head);

}