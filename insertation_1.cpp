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
void insertValueAtHead(Node *&head, int val)
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
        cout<<"->"<<temp->value;
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{

    Node* head = NULL;

    insertValueAtHead(head, 1);
    display(head);

    insertValueAtHead(head, 2);
    display(head);

    insertValueAtHead(head, 3);
    display(head);
}