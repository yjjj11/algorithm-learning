#include<stdafx.h>
using namespace std;
class String {
public:
	String() = default;
	String(const char* str) {
		cout << "Created\n";
		size = strlen(str);
		buffer = new char[size];
		memcpy(buffer, str, size);
	}
	String(const String& other) {
		cout << "Copied\n";
		size = other.size;
		buffer = new char[size];
		memcpy(buffer, other.buffer, size);
	}


	String(String&& other) noexcept{
		cout << "Move\n";
		size = other.size;
		buffer = other.buffer;

		other.size = 0;
		other.buffer = nullptr;
	}
	String& operator=(String&& other) noexcept{
		cout << "MOVE!\n";
		delete[] buffer;
		if (this != &other) {
			size = other.size;
			buffer = other.buffer;

			other.buffer = nullptr;
			other.size = 0;
		}
		return *this;
	}
	~String() {
		delete[] buffer;
		cout << "Destroyed\n";
	}

	void print() {
		for (int i = 0; i < size; i++)cout << buffer[i];
		cout << "\n";
	}
private:
	uint32_t size;
	char* buffer ;
};

class Entity {
public:
	Entity(const String& Name) :name(Name) {};

	Entity(String&& Name) :name(move(Name)) {};

	void printname() { name.print(); }

private:
	String name;
};
int main() {

	Entity entity("cherno");
	//Entity entity(String("cherno"));实际上等同于这个
	//有一个隐式转换
	//先转换成String存放在一个临时变量里Created
	//然后调用复制构造函数在栈上开一个结构体做浅拷贝
	//避免了堆上内存的重新分配
	//将这个浅拷贝送入entity()，然后销毁临时变量(String)cherno
	entity.printname();

	String string = "Hello";
	String des = move(string);//这样是复制一个值给des;
	// 这样是将string移动到dest，舍弃了原来的字符串


	String apple = "Apple";
	String dest;
	cout << "Apple "; apple.print();

	cout << "Dest "; dest.print();
	//String des = string;//这样是复制一个值给des;
	dest = move(apple);
	//这两种等号方式是不一样的，前者在创造变量，后者在移动变量
	cout << "Apple "; apple.print();
	cout << "Dest "; dest.print();

	//move就是将一个已经存在的变量转换为一个临时变量
	//临时变量属于右值，因此可以去使用移动构造函数或者移动运算符
	cin.get();
}