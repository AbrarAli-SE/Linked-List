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
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insertNodeAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertNodeAtTail(int val)
    {
        if (head==NULL)
        {
            insertNodeAtHead(val);
        }

        Node* current = head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        Node *newNode = new Node(val);
        current->next=newNode;
        tail=newNode;
        newNode->prev=current;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {

            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayReverse()
    {
        Node *temp = tail;
        while (temp != NULL)
        {

            cout << temp->value << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
int main()
{
    DoublyLinkedList dll;
    dll.insertNodeAtHead(10);
    dll.insertNodeAtHead(20);
    dll.insertNodeAtHead(30);
    dll.insertNodeAtTail(40);
    dll.insertNodeAtTail(50);
    dll.insertNodeAtTail(60);

    dll.display();
    dll.displayReverse();
}