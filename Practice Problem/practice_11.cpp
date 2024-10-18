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
        cout << " " << temp->value;
        temp = temp->next;
    }
    cout << endl;
}

void sorting(Node *&head)
{
    Node *temp = head;
    Node *tempNext;

    while (temp != NULL)
    {
        tempNext = temp->next;
        while (tempNext != NULL)
        {
            if (temp->value > tempNext->value)
            {
                int t = temp->value;
                temp->value = tempNext->value;
                tempNext->value = t;
            }
            tempNext = tempNext->next;
        }
        temp = temp->next;
    }
}
int main()
{
    int size, value;
    Node *head = NULL;
    cout << "How much value that you want to store in list : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Value " << i + 1 << " : ";
        int val;
        cin >> val;
        insertValueAtHead(head, val);
    }
    cout << "\nOrignal List : ";
    display(head);

    sorting(head);
    cout << "\nSorted  List : ";
    display(head);
}