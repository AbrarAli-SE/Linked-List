// swaping and sorting
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
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " -> " << temp->value;
        temp = temp->next;
    }
    cout << endl;
}
void sortList(Node *&head)
{
    Node *currentNode = head;
    Node *nextNode = head->next;
    // int shortedIndex=0;
    while (currentNode != NULL)
    {
        while (nextNode != NULL)
        {
            if (currentNode->value > nextNode->value)
            {
                int temp = currentNode->value;
                currentNode->value = nextNode->value;
                nextNode->value = temp;
            }
            nextNode = nextNode->next;
        }
        currentNode = currentNode->next;
    }
}
int main()
{
    int size, value;
    Node *head = NULL;
    cout << "How much value that you want to store in list : ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;

        insertValueAtHead(head, value);
    }
    cout << "\nOrignal List:\n";
    display(head);

    sortList(head);

    cout << "\nUpdate List:\n";
    display(head);
}