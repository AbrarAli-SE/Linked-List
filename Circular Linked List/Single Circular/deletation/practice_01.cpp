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
void deleteAtHead(Node *&head)
{
    Node* tail = head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }
    head=head->next;
    tail->next= head;
    return;
}
void deleteAtTail(Node *&head)
{
    Node *previous=head;
    while(previous->next->next!=head)
    {
        previous=previous->next;
    }
    previous->next=head;
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
    display(head);

    deleteAtHead(head);
    display(head);

    deleteAtTail(head);
    display(head);
    return 0;
}