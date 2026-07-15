#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> array;
    for(int i=0;i<10;i++)
    {
        array.push_back(i);
        // 末尾追加
    }

    // 中间插入
    array.insert(array.begin()+2,666);

    // 末尾删除元素
    array.pop_back();

    // 删除中间元素
    array.erase(array.begin()+2);

    // 根据元素值查找index
    int index = find(array.begin(),array.end(),3) -array.begin();
    /* 原理：从开头开始寻找，寻找到元素为对应值的索引迭代器（相当于一个指针），
    最后减去0的位置索引，返回我们想要的索引，假设没有对应元素，则返回数组末尾
    最坏的时间复杂度是o（N）*/
    
    cin.get();
}