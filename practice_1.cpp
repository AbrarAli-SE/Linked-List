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
int main()
{

    Node* head=new Node(1);

    cout<<head->value<<" "<<head->next;

}