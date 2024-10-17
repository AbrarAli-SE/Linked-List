#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};
class DoubleCircularLinkedList
{
public:
    Node *head;
    Node *tail;

    DoubleCircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = newNode;
            head->prev = newNode;
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        newNode->prev = tail;
        head = newNode;
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if(head==NULL)
        {
            insertAtHead(val);
            return;
        }
        newNode->next=head;
        tail->next=newNode;
        head->prev=newNode;
        newNode->prev=tail;

        tail=newNode;

    }
    void display()
    {
        Node *temp = head;
        do
        {

            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void displayReverse()
    {
        Node *temp = tail;
        do
        {

            cout << temp->value << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }

};
int main()
{
    DoubleCircularLinkedList dcll;
    dcll.insertAtHead(10);
    dcll.insertAtHead(20);
    dcll.insertAtHead(30);
    dcll.insertAtHead(40);
    dcll.insertAtHead(50);
    dcll.insertAtTail(60);

    dcll.display();
    dcll.displayReverse();
}