#include<iostream>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
    Node(int val)
    {
        value=val;
        next= NULL;
    }
};
void insertValue(Node* &head,int val)
{
    Node* newNode = new Node(val);
    newNode->next=head;
    head=newNode;
}
void display(Node* head )
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value<<"\n->";
        temp=temp->next;
    }
}
int main()
{

    Node* head = NULL;
    for(int i=0;i<15;i++)
    {
    insertValue(head,i);
    }
    display(head);

}