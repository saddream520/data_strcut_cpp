#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,string>text;
    text["zoo"] = "zoo_visit";
    text["car"] = "Toyota";
    cout<<text.size();
    // find方法，这是map映射中寻找一个键的方法，他找不到会返回一个该hash.end()，即是末尾迭代器
    cin.get();
}