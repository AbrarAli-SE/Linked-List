#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    Node *prev;
    int value;
    Node(int val)
    {

        value = val;
        next = NULL;
        prev = NULL;
    }
};
class DoubleLinkedList
{
public:
    Node *head;
    Node *tail;

    DoubleLinkedList()
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
    void deleteAtTail()
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    void deleteAtStart()
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    void deleteAtSpecificIndex(int pos)
    {
        Node* previouNode = head;
        int previousPosition = 1;
        while(previouNode!=NULL && previousPosition!=pos-1)
        {
            previousPosition++;
            previouNode=previouNode->next;
        }
        Node* temp = previouNode->next;
        previouNode->next=previouNode->next->next;
        previouNode->next->prev=previouNode;
        free(temp);
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
    DoubleLinkedList dll;
    dll.insertNodeAtHead(10);
    dll.insertNodeAtHead(20);
    dll.insertNodeAtHead(30);
    dll.insertNodeAtHead(40);
    dll.insertNodeAtHead(50);
   
    dll.deleteAtSpecificIndex(3);

    dll.display();
    dll.displayReverse();
}