#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    // 利用键值对映射的方法，我们可以做到用空间换时间，极大提高效率
    // 使用范围不亚于查重，寻找目标值等
    unordered_map<string,string>text;
    text["zoo"] = "zoo_visit";
    text["car"] = "Toyota";
    cout<<text.size();
    // find方法，这是map映射中寻找一个键的方法，他找不到会返回一个该hash.end()，即是末尾迭代器
    cin.get();
}