// comparision of two linked list
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
int sizeOfList(Node *&head)
{
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
void compareList(Node *&head1, Node *&head2)
{
    bool equal = false;
    if (sizeOfList(head1) == sizeOfList(head2))
    {
        Node *temp1 = head1;
        Node *temp2 = head2;
        while (temp1 != NULL)
        {
            if (temp1->value == temp2->value)
            {
                equal = true;
            }
            else
            {
                equal=false;
                break;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    if (equal)
    {
        cout << "\nBoth lists Are equal";
        return;
    }
    else
        cout << "\nlists Are unequal";
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    insertValueAtHead(head1, 1);
    insertValueAtHead(head1, 2);
    insertValueAtHead(head1, 3);

    insertValueAtHead(head2, 1);
    insertValueAtHead(head2, 2);
    insertValueAtHead(head2, 3);
    
    display(head1);
    display(head2);

    compareList(head1, head2);
}