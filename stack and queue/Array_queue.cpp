#include<iostream>
#include<string>
using namespace std;
template<typename T>
class myArrayQueue
{
private:
    T*data;
    int cap;
    int front;
    int rear;
    int size;
public:
    myArrayQueue(int capcity)
    :data(0),cap(capcity),front(0),rear(0),size(0)
    {
        data = new T[capcity];
    }

    T enqueue(const T&e)
    {
        if(!judgeEmpty())
        {
            return 0;
        }
        data[rear] = e;
        rear++;
        size++;
        return 1;
    }
    T dequeue()
    {
        T queueTopVal = data[front];
        front++;
        size--;
        return queueTopVal;
    }
    
    T getqueueFirst()
    {
        return data[front];
    }

    T judgeEmpty()
    {
       if(front>0)
       {
        int Remain_position = front;
        for(int i = front ; i<rear;i++)
        {
            data[i-front] = data[front];
        }
        front=0;
        rear =rear - Remain_position;
       }
       return 1;
    }
};
int main()
{
    myArrayQueue<int>queue(10);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.dequeue();
    cout<<"queue first:"<<queue.getqueueFirst();
    return 0;
}