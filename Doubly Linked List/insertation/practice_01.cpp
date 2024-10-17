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
    
};
int main()
{
    DoublyLinkedList dll;
    dll.insertNodeAtHead(10);
    dll.insertNodeAtHead(20);
    dll.insertNodeAtHead(30);
    dll.insertNodeAtHead(50);
    dll.insertNodeAtHead(70);
    dll.display();
}