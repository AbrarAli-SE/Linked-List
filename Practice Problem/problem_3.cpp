// 3. Write a C++ program to create a singly linked list of n nodes
// and count the number of nodes.
// Test Data : Original Linked list : 13 11 9 7 5 3 1
// Number of nodes in the said Linked list : 7
// solution
#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node() {}
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};
void insert(Node *&head, int val)
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
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
int countNode(Node *&head)
{
    Node* temp = head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
int main()
{
    Node *head = NULL;
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value " << i + 1 << " : ";
        int val;
        cin >> val;
        insert(head, val);
    }
    cout << "\nGiven List : ";
    display(head);
    cout<<"\nTotal Nodes :"<<countNode(head);
}
//done