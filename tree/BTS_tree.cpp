#include<iostream>
#include<vector>
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
    // 递归遍历
    // 其中前中后序的顺序不同实则时插入代码的运行时机不同
    void traverse(treeNode*root)
    {
        if(root == nullptr)
        {
            return ;
        }
        // 前序：和根节点移动的顺序相同
        traverse(root->left);
        // 中序：遍历完左子树后再载入节点顺序
        traverse(root->right);
        // 后序：遍历完左右子树再载入节点顺序

        // 批注：实则和递归的顺序实际有关，左右反过来那么中后序也会反过来
    }
};