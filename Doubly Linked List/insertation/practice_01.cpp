#include<iostream>
using namespace std;
class Node
{
    public:
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value=val;
        next = NULL;
        prev = NULL;   
    }
};
class DoublyLinkedList
{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void insertNodeAtHead()
    {

        
    }


};