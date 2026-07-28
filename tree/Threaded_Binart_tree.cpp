#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
enum Tag
{
    Link,Thread
    // link = 0表示指向孩子节点，thread=1表示指向前驱节点或者后继节点
};
class treeNode
{   // 利用空指针域留下线索去检索前驱后继
    // 注意我们这里是根据中序排序来进行递归遍历，那么去顺序是先左子树->根->右子树
    // 所以我们先从左子树开始去寻找哪一个前驱节点,假设左指针为空,让其指向中序遍历前一个节点
    // 接着假设右指针为空,则让其指向中序遍历中的后一个节点
    // 其中我们需要一个pre指针去记录作为线索的指针
public:
    int val;
    treeNode*left;
    treeNode*right;
    // 线索化后左右节点存储的可能是孩子(节点),也可能是线索
    Tag latg,rtag;
  
    treeNode(int x)
    :val(x),left(nullptr),right(nullptr),latg(Link),rtag(Link)
    {

    }
    
    void InThreading(treeNode*p, treeNode*pre)
    {
        if(p==nullptr)
        {
            return;
        }
        if(p)
        {
            InThreading(p->left,pre);
            if(p->left==nullptr)//前驱线索化
            {
                p->latg=Thread;
                p->left =pre;//更新记录
            }
            if(pre->right==nullptr&&pre!=nullptr)
            {
                pre->rtag=Thread;
                pre->right=p;//更新记录
            }
            pre = p;
            InThreading(p->right,pre);
        }
    }
};
