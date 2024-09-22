// bubble sorting
//  swaping and sorting
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
    Node *currentNode;
    Node *lastSorthedNode=NULL;
    bool swap;
    do 
    {
        swap=false;
        currentNode=head;
        while (currentNode->next!=lastSorthedNode)
        {
            if (currentNode->value > currentNode->next->value)
            {
                int temp = currentNode->value;
                currentNode->value = currentNode->next->value;
                currentNode->next->value = temp;
                swap=true;
            }
            currentNode = currentNode->next;
        }
        lastSorthedNode=currentNode;
    }while(swap);
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