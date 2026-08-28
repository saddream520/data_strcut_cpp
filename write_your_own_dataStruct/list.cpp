#include<iostream>
// #include<list>
using namespace std;
// 创建一个链表类的数据结构
// 基本操作，创节点，连指针
template<typename T>
class list
{
private:
    struct Node
    {
        T val;
        Node*next;
        Node(int value):val(value),next(nullptr){}
    };
    Node*head;
    Node*tail;
    int Size;
public:
    list()
    {
        head = new Node(0);
        tail = head;
        Size = 0;
    }
    ~list()
    {
        delete head;
        delete tail;
        Size = 0;
    }
    void push_back(T e)
    {
        Node*newNode = new Node(e);
        tail->next = newNode;
        tail = newNode;
        Size++;
    }
    T pop_back()
    {
        Node* p = head;
        while(p->next!=tail)
        {
            p = p->next;
        }
        Node *deleteNode = p->next;
        T data = tail->val;
        delete deleteNode;
        p->next = nullptr;
        tail = p;
        Size--;
        return data;
    }
    constexpr int size()
    {
        return Size;
    }
    bool empty()
    {
        if(Size == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void resize(int newSize)
    {
        for(int i = 0;i<newSize;i++)
        {
            Node* newSpace = new Node(0);
            tail ->next = newSpace;
            tail = newSpace;
            Size++;
        }
    }
    void Print()
    {
        Node*p = head->next;
        while(p->next!=nullptr)
        {
            cout<<p->val<<" ";
            p = p->next;
        }
    }
};
int main()
{
    list<int>e;
    e.push_back(1);
    e.push_back(1);
    e.push_back(1);
    e.push_back(1);
    e.push_back(1);
    e.push_back(1);
    e.Print();
    cout<<endl;
    e.resize(10);
    e.Print();
    cout<<endl;
    cout<<"the size is "<<e.size()<<endl;
    e.pop_back();
    e.pop_back();
    e.pop_back();
    e.pop_back();
    e.pop_back();
    e.Print();
    cout<<endl;
    cout<<"the size is "<<e.size()<<endl;


    return 0;
}