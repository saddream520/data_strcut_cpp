#include<iostream>
#include<string>
#include <stdexcept>
#include <vector>
using namespace std;
template<typename T>
class MyLinkedList {
private:
    T* data;
    int size;//value number
    int camp;//vector size
    static const int init_camp = 1;
public:

    MyLinkedList()
    {
        this -> data = new T[init_camp];
        this->size = 0;
        this->camp = init_camp;
    }
    MyLinkedList(int initCap)
    {
        this -> data = new T[initCap];
        this->size = 0;
        this->camp = initCap;
    }
    void addlast(T e)
    {
        if (size == camp)
        {
            resize(camp * 2);
        }
        data[size] = e;
        size++;
    }
    void insertadd(int index, T e)
    {
        if (size == camp)
        {
            resize(camp * 2);
        }
        for (int i = size - 1; i >= index; i--)
        {
            data[i+1] = data[i];
        }
        data[index] = e;
        size++;
    }
    void addifirst(T e)
    {
        insertadd(0, e);
    }

    T removelast()
    {
        if (size == camp / 4)
        {
            resize(camp / 2);
        }
        T deleteValue = data[size - 1];
        data[size - 1] = T();
        return deleteValue;
    }

    T remove_mid(int index)
    {
        if (size == camp / 4)
        {
            resize(camp / 2);
        }
        for (int i = index+1; i < size; i++)
        {
            data[i - 1] = data[i];
        }
        T deleteValue = data[size];
        deleteValue = T();
        size--;
        return deleteValue;
    }

    T removefirst()
    {
        remove_mid(0);
    }
    T change(int index, T new_element)
    {
        T oldVal = data[index];
        data[index] = new_element;
        return oldVal;
    }

    T check(int index)
    {
        return data[index];
    }
    void resize(int new_camp)
    {
        T* temp = new T[new_camp];
        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        delete[]data;
        data = temp;
        camp = new_camp;
    }

    //检索是否正常index
    bool isElementIndex(int index) {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) {
        return index >= 0 && index <= size;
    }
};

int main()
{
    MyLinkedList<int>arr(3);
    for(int i = 0;i<5;i++)
    {
        arr.addlast(i);
    }
     for(int i = 0;i<5;i++)
    {
        cout<<arr.check(i)<<" ";
    }
    cout<<endl;
    // arr.remove_mid(1);
    //  for(int i = 0;i<5;i++)
    // {
    //     cout<<arr.check(i)<<" ";
    // }
    arr.addifirst(666);
    //    for(int i = 0;i<6;i++)
    // {
    //     cout<<arr.check(i)<<" ";
    // }
    arr.change(1,99);
          for(int i = 0;i<6;i++)
    {
        cout<<arr.check(i)<<" ";
    }
    return 0;
}