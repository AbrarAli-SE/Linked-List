#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int value;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};
void inserAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node *&head,int val)
{
    if(head==NULL)
    {
        inserAtHead(head,val);
        return;
    }

    Node *newNode = new Node(val);
    Node *tail = head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }

    tail->next=newNode;
    newNode->next=head;
    return;
}
void display(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->value << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    Node *head = NULL;

    inserAtHead(head, 10);
    inserAtHead(head, 20);
    inserAtHead(head, 30);
    inserAtHead(head, 40);
    insertAtTail(head,50);

    display(head);
    return 0;
}