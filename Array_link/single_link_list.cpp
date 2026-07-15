#include<iostream>
#include<string>
using namespace std;
// 增删改查
// 先连接再置入
// 必须先连接后继节点，不然会丢失
class MylinkList
{
    struct Node
    {
        int val;
        Node*next;

        Node(int value):val(value),next(nullptr)
        {

        }
    };
    // 拥有虚头尾节点的单链表
    Node*head;
    Node*tail;
    int size;

public:
    MylinkList()
    {
        head =new Node(0);
        head = tail;
        size = 0;
    }
    ~MylinkList()
    {
        delete head;
        delete tail;
    }
    void addFirst(int e)
    {
        Node*newNode =new Node(e);
        newNode->next = head->next;
        head->next =newNode;
        if(size ==0)
        {
            tail = newNode;
            // 假设只有一个节点，那么我们尽管就让这一个节点成为尾巴好了
        }
        size++;
    }

    void addLast(int e)
    {
        Node* newNode = new Node(e);
        tail->next = newNode;
        tail = newNode;
        // 让尾插入的成为新尾巴
        size++;
    }

    void addAtInsert(int index , int e)
    {
        if(size == index)
        {
            addLast(e);
            return ;
        }
        Node* newNode = new Node(e);
        Node*p =head; //游标指针
        for(int i=0;i<index;i++)
        {
            p=p->next;
            // 寻找前驱节点
        }
        newNode->next = p->next;
        p->next =newNode;
        // 移除，并重新连接
        size ++;

    }

    int removeFirst()
    {
        Node*first_val = head ->next;
        head->next= first_val->next;
        if(size ==1)
        {
            head = tail;
        }
        int delete_val = first_val->val;
        size --;
        delete first_val;
        return delete_val;
    }

    int removeLast()
    {
        Node* p =head;
        while(p->next!=tail)
        {
            p = p->next;
        }
        int delete_val =p->val;
        delete tail;
        p->next = nullptr;
        tail = p;
        size --;
        return delete_val;
    }

    int removeAtIndex(int index)
    {
        Node* p =head;
        for(int i = 0;i<index;i++)
        {
            p=p->next;
        }
        // 拿到前驱节点
        Node* deleteNode = p->next;
        p->next = deleteNode->next;
        
        size--;
        int todelete = deleteNode ->val;
        delete deleteNode;
        return todelete;
    }

    int getfirst()
    {
        return head->next->val;
    }

    int getlast()
    {
        return tail->val;
    }

    int getIndex(int index)
    {
        Node* p =getNode(index);
        return p->val;
    }
    
    int set(int index , int e)
    {
        Node* p = getNode(index);
        int old_val = p->val;
        p->val =e;
        return old_val;
    }
    Node* getNode(int index)
    {
        Node*p=head->next;
        for(int i=0;i<index;i++)
        {
            p=p->next;
        }
        return p;
    }

};