#include<iostream>
#include<cstring>
#include<chrono>
#define originSize 1
//#include<vector>
using namespace std;
//做一个属于自己的向量类
// 特点：内存连续（那么其实就是一个数组），自动扩容（不够就触发resize，但是需要拷贝）
//每次填入元素，我们需要自动扩容一个空间
template<typename T>
class vector
{
public:
	vector():Size(0),capacity(0){}
	~vector() { Size = 0;  delete[]Array; }
	T& operator[](int index) { return Array[index]; }
	const T& operator[](int index)const { return Array[index]; }
	//将元素添加到末尾
	void push_back(T val)
	{
		resize();
		Array[Size] = val;
		Size++;
		
	}
	// 自动扩容，拷贝-添值-删除
	void resize()
	{
		if (capacity == 0)
		{
			capacity = 1;
			Array = new T[originSize];
		}
		else if (Size < capacity) return;
		else if (Size >= capacity)
		{
			// Array = new T[Size + 1];
			capacity = capacity*2;
			T* newArray = new T[capacity];
			for(int i = 0;i<Size;i++)
			{
				newArray[i] = Array[i];
			} 
			delete[] Array;
			Array = newArray;
		}
	}
	//返回空间大小
	constexpr int size()
	{
		return Size;
	}
	//判空
	const bool empty()
	{
		if (Size == 0) return true;
		else return false;
	}
	// 提前预留空间
	void reserve(int space)
	{
		Array = new T[space];
		capacity = space;
	}
	int return_Capacity()
	{
		return capacity;
	}
	T* begin()
	{
		return Array;
	}
	T* end()
	{
		return Array + Size;
	}
	const T* begin()const
	{
		return Array;
	}
	const T* end()const
	{
		return Array + Size;
	}
private:
	T* Array;
	int Size;
    int capacity;
};
class Timer
{
public:
	std::chrono::time_point<std::chrono::high_resolution_clock>start, end;
	chrono::duration<float>duration;
public:
	Timer()
	{
		start = chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		cout << "Timer took" << ms << "ms" << endl;
	}
};
int main()
{
	vector<int>data;
	data.reserve(10);
	cout <<"the array capacity is " << data.return_Capacity() << endl;
	cout<<"the value nums is  " << data.size() << endl;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(4);
	data.push_back(5);

	//for (int i = 0; i < data.size(); i++)
	//{
	//	cout << "the val is " << data[i] << endl;
	//}
	for (auto it = data.begin(); it < data.end(); ++it)
	{
		int x = *it;
		cout << x << " ";
	}
	return 0;
}