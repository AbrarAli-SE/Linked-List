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
    Node() {}
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
void insertValueAtSpacificPoint(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertValueAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int currentPos = 0;
    while (currentPos != pos - 1)
    {
        temp = temp->next;
        currentPos++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void updateValue(Node *&head, int val, int pos)
{
    Node *temp = head;
    int currentPos = 0;
    while (currentPos != pos)
    {
        temp = temp->next;
        currentPos++;
    }
    temp->value = val;
}
void deletationAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}
void deletationAtTail(Node* &head)
{
    Node *secondLast = head;

    while (secondLast->next->next != NULL)
    {
        secondLast=secondLast->next;
    }
    Node* temp = secondLast->next;
    secondLast->next=NULL;
    free(temp); 
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

    insertValueAtSpacificPoint(head, 7, 3);
    display(head);

    updateValue(head, 10, 3);
    display(head);

    deletationAtHead(head);
    display(head);

    deletationAtTail(head);
    display(head);
}