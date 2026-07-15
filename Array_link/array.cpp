#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int array[10];
    //增
    for(int i=0;i<10;i++)
    {
        array[i]=i;
    }
    for(int i=0;i<10;i++)
    {
    // cout<<array[i];
    }
  
    //静态数组动态插入
  //indexs = 2的位置插入一个数字
    int insert[10];
    for(int i =0;i<5;i++)
    {
        insert[i] = i;
    }
    for(int i =5 ;i>2;i--)
    {
        insert[i]=insert[i-1];
    }
    insert[2]=666;
     for(int i =0;i<6;i++)
    {
        // cout<<insert[i]<<" ";
    }
  
    //删除一个元素
    //删除index=1的元素
    int deleteArray[10];
    for(int i = 0;i<5;i++)
    {
        deleteArray[i]=i;
    }
    for(int i =0;i<5;i++)
    {
       cout<<deleteArray[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<4;i++)
    {
        deleteArray[i]=deleteArray[i+1];
    }
    // deleteArray[1]=-1;
    for(int i =0;i<5;i++)
    {
       cout<<deleteArray[i]<<" ";
    }
 return 0;
    
}