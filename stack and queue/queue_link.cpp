#include<iostream>
#include<string>
using namespace std;
class myLinkQueue
{
    struct Node
    {
        int val;
        Node* next;
        Node* prev;
        Node(int val):val(val),next(nullptr),prev(nullptr)
        {

        }
    };
    Node*head;
    Node*tail;
    int size;
public:
    myLinkQueue()
    {
        head = new Node(0);
        tail = new Node(0);
        size = 0;
        head ->next =tail;
        tail ->prev =head;
    }
    ~myLinkQueue()
    {
        delete head;
        delete tail;
    }

    void enqueue(int e)
    {
        Node*val= new Node(e);
        Node*temp = tail->prev;
        temp->next =val;
        val ->next =tail;
        tail ->prev =val;
        size++;
    }

    void dequeue()
    {
        Node*val=head->next;
        Node*temp = val ->next;
        head->next =temp;
        temp->prev =head;
        delete val;
        val ->next=nullptr;
        val->prev=nullptr;
        size--;
    }

    int getQueueFirst()
    {
        return head->next->val;
    }
};
int main()
{
    myLinkQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.dequeue();
    cout<<"top queue:"<<queue.getQueueFirst();
    return 0;
}