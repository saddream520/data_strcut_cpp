#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class tree_Node
{
public:
    int val;
    tree_Node*left;
    tree_Node*right;
tree_Node(int x)
:val(x),left(nullptr),right(nullptr)
{

}
};
void travers(tree_Node*root)
{
    if(root==nullptr)
    {
        return;
    }
    travers(root->left);
    travers(root->right);
}
int leaf_sum(tree_Node*root)
{
     if(root==nullptr)
    {
        return 0;
    }
    if(!root->left&&!root->right)
    return 1;
    return leaf_sum(root->left)+leaf_sum(root->right);
}

int all_leaf_sum(tree_Node*root)
{
     if(root==nullptr)
    {
        return 0;
    }
    if(!root->left&&!root->right)
    return 1;
    return all_leaf_sum(root->left)+all_leaf_sum(root->right)+1;
}

int all_leaf_sum(tree_Node*root)
{
     if(root==nullptr)
    {
        return 0;
    }
    if(!root->left&&!root->right)
    return 0;
    return all_leaf_sum(root->left)+all_leaf_sum(root->right)+1;
}
int tree_depth(tree_Node*root)
{
    if(root==nullptr)
    return 0;
    return tree_depth(root->left)>tree_depth(root->right)?tree_depth(root->left)+1:tree_depth(root->right);
}
pair<int,int> MaxMinleaf(tree_Node*root)
{
    if(root==nullptr)
    {
      return{0,0};
    }
    auto[max_1,min_1] = MaxMinleaf(root->left);
    auto[max_a,min_a] = MaxMinleaf(root->right);
    int maxD = max(max_1,max_a)+1;
    int minD = min(min_1,min_a)+1;
    return {maxD,minD};
}
void anthotherMaxMin(tree_Node*root,int& maxD,int& minD)
{
    if(root == nullptr)
    {
        return;
    }
    int max_1,max_a;
    int min_1,min_a;
    
    anthotherMaxMin(root->left,max_1,min_1);
    anthotherMaxMin(root->right,max_a,min_a);
    int len_1 = max_1;
    int len_2 = max_a;
    maxD =(len_1>len_2?len_1:len_2);
    minD =(len_1<len_2?len_1:len_2);
}
//判断两棵树是否相似
int tree_similar(tree_Node*r1,tree_Node*r2)
{
    if(r1==nullptr&&r2==nullptr)
    return 1;
    if((r1==nullptr&&r2!=nullptr)||(r1!=nullptr&&r2==nullptr))
    return 0;
    if(tree_similar(r1->left,r2->left))//左子树相似就递归遍历右子树
    return tree_similar(r1->right,r2->right);
    else
    return 0;
}

void tree_swap(tree_Node*root)
{
    tree_Node*p;
    if(root==nullptr)
    {
        return;
    }
    if(root->left!=nullptr || root->right!=nullptr)
    {
        p=root->left;
        root->left=root->right;
        root->right=p;
    }
        tree_swap(root->left);
        tree_swap(root->right);
}

void tree_swapChild(tree_Node*root)
{
    tree_Node*p;
    if(root==nullptr)
    {
        return;
    }
    if(root->left!=nullptr || root->right!=nullptr)
    {
        p=root->left;
        root->left=root->right;
        root->right=p;
    }
    if(root->left!=nullptr)
        tree_swap(root->left);
    if(root->right!=nullptr)
        tree_swap(root->right);
}
int main()
{
    tree_Node*root =new tree_Node(1);
    root->left = new tree_Node(2);
    root->right = new tree_Node(3);
    root->left->left = new tree_Node(4);
    root->left->right = new tree_Node(5);
    root->right->left = new tree_Node(6);
    root->right->right = new tree_Node(7);
    cout<<"leaf_sum:"<<leaf_sum(root)<<endl;
    cout<<"not_leaf_sum:"<<all_leaf_sum(root);
    cin.get();
}