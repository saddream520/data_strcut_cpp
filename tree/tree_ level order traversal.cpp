#include<iostream>
#include<queue>
#include<deque>
#include<string>
using namespace std;
class treeNode
{
    public:
    int val;
    treeNode*left;
    treeNode*right;
    treeNode(int x)
    :val(x),left(nullptr),right(nullptr)
    {

    }
    void levelOrederTraverse(treeNode* root)
    {
        if(root == nullptr)
        {
            return ;
        }
        queue<treeNode*>q;
        q.push(root);
        int depth = 1;//root节点深度1
        // 得到深度的写法
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
            // 切换层的条件是当前层的节点已经全部出队，队列中剩下的就是下一层的节点
            treeNode*cur =q.front();//得到队头元素
            q.pop();
            // 先入先出原则
            cout<<cur->val<<endl;
            if(cur->left!=nullptr)
            {
                q.push(cur->left);
            }
             if(cur->right!=nullptr)
            {
                q.push(cur->right);
            }
            }
            depth++;
        }
    }
};
// 层序遍历的本质是广度优先搜索 (BFS)，我们用一个队列来"排队"：

// 入队 = 预约将来要访问的节点（孩子节点）
// 出队 = 完成当前节点的访问，轮到下一个