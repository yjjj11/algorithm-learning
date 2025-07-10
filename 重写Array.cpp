#include<stdafx.h>
using namespace std;

template<typename T,size_t S>
class Array {
public:
	
	const T& operator[](size_t index)const { return data[index]; }
	//返回值不能被修改并且函数内部不能修改类的非static成员
	T& operator[](size_t index) 
	{ 
		if(!(index<S))
		{
			__debugbreak();
		}
		return data[index];
	}//边界检查

	constexpr size_t Size() const { return S; }

	T* DATA() { return data; }
	const T* DATA() const { return data; }
private:
	T data[S];
};
//Array是在栈上分配的数组
int main() {
	size_t size = 5;
	int arrays[5];//栈分配
	int* heaparray = new int[size];//堆分配
	delete[] heaparray;

	array<int, 10>a;
	size = a.size();


	size = 5;
	Array<int,5> data;

	static_assert(data.Size() < 100, "Too Large\n");


	memset(data.DATA(), 0, sizeof(int)*data.Size());
	//memset(&data[0], 0, sizeof(int)*data.Size());
	for (int i = 0; i < data.Size(); i++)
	{	
		data[i] = 2;
		cout << data[i] << "\n";
	}

	for (auto& node : data.DATA())cout << node << "\n";
}