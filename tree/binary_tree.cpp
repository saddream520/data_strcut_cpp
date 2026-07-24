#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
class binary_tree_node
{
public:
    int data;
    binary_tree_node*left;
    binary_tree_node*right;
    binary_tree_node(int x)
    :data(x),left(nullptr),right(nullptr)
    {

    }
};

int main()
{
    binary_tree_node* root = new binary_tree_node(1);
    root ->left = new binary_tree_node(2);
    root->right = new binary_tree_node(3);
    root->left->left = new binary_tree_node(4);
    root->left->right = new binary_tree_node(5);
    root->right->left = new binary_tree_node(6);
    root->right->right = new binary_tree_node(7);
    //       1
    //    /    \
    //   2      3
    //  / \    /  \
    // 4   5  6    7


// 用哈希表思想构筑二叉树
// 1 -> {2, 3}
// 2 -> {4}
// 3 -> {5, 6}

unordered_map<int, vector<int>> tree;
tree[1] = {2, 3};
tree[2] = {4};
tree[3] = {5, 6};
    cin.get();
}