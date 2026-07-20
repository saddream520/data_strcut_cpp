#include<iostream>
#include<string>
using namespace std;
template<typename T>
class myArrayStack
{
    int cap;
    T*data;
    int top;
    int size;

    public:
    myArrayStack(int cap)
    :cap(cap),top(-1),data(0),size(0)
    {
        data = new T(cap);
    }
    T push(const T&e)
    {
        data[++top] = e;//前提的得先自增；
        size++;
        return data[top];
        
    }

    T pop()
    {
        T val = data[top--];
        size--;
        return val;
    }

    T getTop()
    {
        return data[top];
    }

    void display()
    {
        cout<<"all val:"<<endl;
        for(int i = 0;i<size;i++)
        {
            cout<<" "<<data[i];
        }
    }
};

int main()
{
    myArrayStack<int>stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.display();
    cout<<endl;
    cout<<"pop val:"<<stack.pop()<<endl;
    cout<<"top val:"<<stack.getTop();
    return 0;
}
