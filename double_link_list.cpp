#include<iostream>
#include<string>
using namespace std;
// 基本思路
// 依旧基本的增删改查
// 先知道前后驱节点，再连接前后节点
// 使用虚头尾节点，更好的定位
// 开始
class double_link
{
    struct Node
    {
        int val;
        Node* next;
        Node* prev;

        Node(int value)
        :val(value),next(nullptr),prev(nullptr)
        {

        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    double_link()
    {
        head =new Node(0);
        tail = new Node(0);
        size=0;
        head->next =tail;
        tail->prev = head;
    }
    ~double_link()
    {
        while(size>0)
        {
            removeFirst();
        }
        delete head;
        delete tail;
    }

    void addFirst(int e)
    {
        Node* x =new Node(e);
        Node* temp = head->next;
        // head ->temp

        temp->prev = x;
        x->next = temp;
        //  x<->temp

        head ->next =x;
        x->prev =head;
        // head <-> x <-> temp
        size++;
    }
    
    void addLast(int e)
    {
        Node*x =new Node(e);
        Node*temp =tail->prev;
        // temp -> tail
        
        temp->next = x;
        x->prev = temp;
        // temp <-> x 

        x->next =tail;
        tail->prev = x;
        // temp <-> x <->tail

        size++;
    }

    void addIndex(int index, int e)
    {
        if(index == size)
        {
            addLast(e);
        }

        Node* p =getNode(index);
        // 找到你能插入的地方
        Node* temp = p->prev;
        //temp -> p

        Node*x =new Node(e);

        p->prev = x;
        temp->next =x;
        x->next = p;
        x->prev = temp;

        // temp <-> x <p

        size++;
    }

    int removeFirst()
    {
        Node*x =head->next;
        Node* temp =x->next;

        head->next =temp;
        temp->prev =head;

        int delete_val =x->val;
        delete x;
        x->next =nullptr;
        x->prev =nullptr;
        size--;
        return delete_val;
    }

    int removeLast()
    {
        Node*x =tail->prev;
        Node*temp = x->prev;

        tail->prev =temp;
        temp->next = tail;

        int delete_val = x->val;
        x->next=nullptr;
        x->prev=nullptr;
        delete x;
        size -- ;
        return delete_val;
    }

    int removeIndex(int index)
    {
        Node*x= getNode(index);
        Node*temp_1 = x->prev;
        Node*temp_2 = x->next;

        temp_1->next = temp_2;
        temp_2->prev = temp_1;

        int delete_val = x->val;
        x->next = nullptr;
        x->prev = nullptr;
        size--;
        return delete_val;
    }

    int get(int index)
    {
        checkValIndex(index);
        Node*p = getNode(index);
        return p->val;
    }

    int set(int index , int e)
    {
        Node* p =getNode(index);
        int old_val = p->val;
        p->val =e;
        return old_val;
    }

    Node* getNode(int index)
    {
        Node*p =head->next;
        for(int i =0;i<index;i++)
        {
            p=p->next;
        }
        return p;
    }

    bool isPositionIndex(int index) const{
        return index >= 0 && index <= size;
    }

    int checkValIndex(int index) const
    {
        if(! isPositionIndex(index))
        {
            int error = -1;
            return error;
        }
    }
};