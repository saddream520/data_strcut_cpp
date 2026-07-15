#include<iostream>
#include<string>
#include<vector>
using namespace std;
class mylinkStack
{
    struct Node
    {
        int val;
        Node*next;

        Node(int val):val(val),next(nullptr)
        {

        }
    };
    Node*head;
    int size;

public:
    mylinkStack()
    {
        head =new Node(0);
        size = 0;
    }
    ~mylinkStack()
    {
        delete head;
    }

    void push(int e)
    {
        Node* newNode = new Node(e);
        newNode->next = head->next;
        head = newNode;
        size++;
    }
    void pop()
    {
        Node*topVal =head;
        head = head->next;
        int returnVal = topVal->val;
        delete topVal;
        size--;
    }

    int getTop()
    {
        if(size == 0)
        return -1;

        return head->val;
    }

    int getNumber()
    {
        if(size == 0)
        return -1;
        return size;
    }
};
int main()
{
    mylinkStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout<<"top value:"<<stack.getTop();
    cin.get();
}