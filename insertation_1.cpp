#include<iostream>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
    Node(int val)
    {
        value=val;
        next= NULL;
    }
};
void insertValue(Node* &head,int val)
{
    Node* newNode = new Node(val);
    newNode->next=head;
    head=newNode;
}

int main()
{

    Node* head=new Node(1);

    cout<<head->value<<" "<<head->next;

}