#include<iostream>
#include<string>
using namespace std;
template<typename T>
class myArrayStack
{
    int cap;
    T*data;
    int top;

    public:
    myArrayStack(int cap)
    :cap(cap),top(-1),data(0)
    {
        data = new T(cap);
    }
    T push(const T&e)
    {
        data[top++] = e;
        return data[top++];
    }

    T pop()
    {
        T val = data[top--];
        return val;
    }

    T getTop()
    {
        return data[top];
    }
};
