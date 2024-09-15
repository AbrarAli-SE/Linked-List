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
void insertValueAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertValueAtSpacificPoint(Node* &head,int val,int pos)
{
    if(pos==0)
    {
        insertValueAtHead(head,val);
        return;
    }
    Node* newNode= new Node(1);
    Node* temp = head;
    int currentPos = 0;
    while(currentPos!=pos-1)
    {
        temp = temp->next;
        currentPos++;
    }
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " -> " << temp->value;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;

    insertValueAtHead(head, 1);
    display(head);

    insertValueAtHead(head, 2);
    display(head);

    insertValueAtHead(head, 3);
    display(head);

    insertValueAtTail(head, 5);
    display(head);
}