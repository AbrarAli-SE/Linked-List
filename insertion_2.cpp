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
void insertValue(Node* &head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void insertValueAtTail(Node* &head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " -> "<< temp->value ;
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{

    Node *head = NULL;

    insertValue(head, 1);
    display(head);

    insertValue(head, 2);
    display(head);

    insertValue(head, 3);
    display(head);

    insertValueAtTail(head, 5);
    display(head);
} 