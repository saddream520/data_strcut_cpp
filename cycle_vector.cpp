#include<iostream>
#include<ostream>
#include<vector>
using namespace std;
template<typename t>
// 逻辑与物理上得分得清啊
class cycleArray
{
    vector<t>arr;
    int start;
    int end;
    int count;

    void resize(int newSize)
    {
        vector<t>new_array;
        for(int i = 0 ;i<count;i++)
        {
            new_array[i] = arr[newSize+i % arr.size()];
        }
        arr = move(new_array);
        start = 0 ;
        end = count;//解决end == start 判断空满歧义
    }
    
    public:
        cycleArray():cycleArray(1){}

        explicit cycleArray(int size)
        :arr(size),start(0),end(0),count(0){}

        void addFirst(const t&e)
        {
            if(isfull())
            {
                resize(arr.size()*2);
            }

            //闭区间，所以先左移再赋值，对齐
            start = (start -1 +arr.size())%arr.size();
            arr[start] = e;
            count++;
        }

        void addLast(const t&e)
        {
            if(isfull())
            {
                resize(arr.size()*2);
            }
            
            //开区间，先赋值再移动，不对齐
            arr[end] = e;
            end = (end+1)%arr.size();
            count++;

        }       

        void removeFirst()
        {
            arr[start] = t();
            start = (start + 1)% arr.size();
            count--;
        }
        void removeLast()
        {
            end = (end-1+arr.size())%arr.size();
            arr[end] =t();
            count--;
        }

        t getfirst() const{
            return arr[start];
        }

        t getLast() const
        {
            return arr[(end-1+arr.size()) % arr.size()];
        }

        t  checkATInsert(int index) const
        {
            return arr[(start+index-1)%arr.size()];
        }
        void display()
        {
            for(int i =0;i<arr.size();i++)
            {
                cout<<arr[i];
            }
        }
        bool isfull() const{
            return count==arr.size();
        }
        int size() const {
            return count;
        }

        bool isEmpty() const {
            return count == 0;
        }
};
int main()
{
cycleArray<char>array(5);
array.addFirst('A');
array.addFirst('B');
array.addLast('C');
array.addLast('D');
cout<<"the first value:"<<array.getfirst();
cout<<endl;
cout<<"the last value:"<<array.getLast();
cout<<endl;
cout<<"all value:";
array.display();
cout<<endl;
cout<<"check the value:"<<array.checkATInsert(2);
   cin.get();
}