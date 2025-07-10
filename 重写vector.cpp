#include<stdafx.h>
using namespace std;

template<typename T>
class Vector {

private:
	T* data = nullptr;
	size_t size = 0;//当前队列长度
	size_t Capacity = 0;//最大容量

	void ReAlloc(size_t newCapacity) {
		//1.第一次分配内存块
		//2.复制/移动
		//3.delete

		T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

		size = min(size, newCapacity);
		for (size_t i = 0; i < size; i++)newBlock[i] = move(data[i]);
		//这样复制最保险

		::operator delete(data, sizeof(T) * Capacity);
		data = newBlock;
		Capacity = newCapacity;
	}
public:
	Vector() {
		//allocate 2elements
		ReAlloc(2);
	}
	void pb(const T& value) {
		if (size >= Capacity) ReAlloc(size + Capacity / 2);

		data[size] = value;
		size++;
	}

	void pb(const T&& value) {
		if (size >= Capacity) ReAlloc(size + Capacity / 2);

		data[size] = move(value);
		size++;
	}

	template<typename... Args>
	T& emplaceback(Args&&... arg) {
		if (size >= Capacity) ReAlloc(size + Capacity / 2);
		/*data[size] = T(forward<Args>(arg)...);*/
		new(&data[size]) T(forward<Args>(arg)...);
		return data[size++]; 
	}

	T& operator[](size_t index) { return data[index]; }
	const T& operator[](size_t index)const { return data[index]; }
	
	size_t Size()const { return size; }

	void popback() {
		if (size > 0) {
			size--;
			data[size].~T();
		}
	}

	void clean() {
		for (int i = 0; i < size; i++)data[i].~T();
		size = 0;
	}
	~Vector() {
		::operator delete(data, sizeof(T) * Capacity);
	}
};



struct node {
	int x, y, z;
	int* block=nullptr;
	node() { block = new int[5]; };
	node(int p) :x(p), y(p), z(p) { block = new int[5]; }
	node(int x, int y, int z) :x(x), y(y), z(z) { block = new int[5]; };

	node(const node& a) = delete;
	node(node&& a) noexcept:x(a.x), y(a.y), z(a.z) {
		cout << "Moved!\n";  
		block = a.block;
		a.block = nullptr;
	};

	~node() { 
		cout << "Destroyed!\n"; 
		delete[] block;
	}

	node& operator=(const node& a) = delete;

	node& operator=(node&& a) {
		x = a.x; y = a.y; z = a.z;
		block = a.block;
		a.block = nullptr;
		cout << "Move\n";
		return *this;
	}

	
};
ostream& operator<<(ostream& stream, const node& me) {
	stream << me.x << "," << me.y << "," << me.z;
	return stream;
}
template<typename T>
void print(const Vector <T>& v) {
	for (size_t i = 0; i < v.Size(); i++)cout << v[i] << "\n";
	cout << "------------------------\n";
}
int main() {
	Vector<node>p;

	p.emplaceback(1);
	p.emplaceback(2,3,4);
	p.emplaceback(4,5,6);
	print(p);


	p.popback();
	print(p);

	p.clean();
	print(p);

	cin.get();
}