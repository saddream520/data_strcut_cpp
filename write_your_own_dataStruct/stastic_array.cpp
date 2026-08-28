#include<iostream>
#include<array>
#include<cstring>
using namespace std;
// 从0开始写自己数据结构————静态数组
// 需要实现的
// 1.返回数组大小
// 2.返回值
// 3.能遍历
// 4.能赋值
template<typename T,size_t S>
class Array
{
public:
    T& operator[](int index)
    {
        return m_data[index];
    }
    // 不加&只是返回值的副本，是无法修改的右值，必须引用才能修改到原数组
    const T& operator[](int index)const
    {
        return m_data[index];
    }
    constexpr int size()const 
    {
        return S;
    }
    T* Data(){return m_data;}
private:
    T m_data[S];
};
int main()
{
    
    Array<int,5>data;
    //  手动赋值
    int n = data.size();
    memset(data.Data(),0,n*sizeof(int));
    // 注意memset要的是内存地址，所以我们返回首地址再隐式转化即可
    // 根据这个原则，我们也可以这样写
    memset(&data[0],0,n*sizeof(int));
    for(int i =0;i<n;i++)
    {
        data[i] = i;
        // 注意这里这里提示我们必须时刻修改的左值,然而我们重载的时候只是返回一个值，并不是可修改的，那该如何去做呢
        cout<<data[i]<<" ";
        // 很明显这时候我们没有对应的操作符，所以直接重载
    }

    return 0;
}