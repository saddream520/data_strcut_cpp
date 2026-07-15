#include<iostream>
#include<vector>
using namespace std;
// 创建一个将数组转换成单链表的工具
// 我们需要头节点，和一个游标指针
//  链表基本思想，先链接，后置入
class LInkNode
{
public:
    int val;
    LInkNode*next;
    LInkNode(int x)
    :val(),next(NULL)
    {

    }
};
LInkNode* createLink(vector<int>arr)
{
    LInkNode*head = new LInkNode(arr[0]);
    LInkNode*cur = head;
    for(int i = 0;i<arr.size();i++)
    {
        cur->next = new LInkNode(arr[i]);
        cur = cur ->next;
    }
    return head;
}