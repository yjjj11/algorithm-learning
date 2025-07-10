#include<stdafx.h>
using namespace std;
struct allocmaybe {
	uint32_t totalallocate = 0;
	uint32_t totalfree = 0;
	int Currentusage() {
		return totalallocate - totalfree;
	}
};
static allocmaybe aa;
void* operator new(size_t size) {
	aa.totalallocate += size;
	return malloc(size);
}
void operator delete(void* memory, size_t size) {
	/*cout << "Freeing  " << size << "Bites\n";*/
	aa.totalfree += size;
	free(memory);
}

void printnowallocusage() {
	cout<<aa.Currentusage()<<"\n";
}
struct node {
	int x, y, z;
	//node(int x,int y,int z) :x(x), y(y), z(z) {};
};
int main() {
	
	printnowallocusage();
	node* n = new node();
	printnowallocusage();
	
	string s = "cherno";
	printnowallocusage();
	{
		unique_ptr<node>obj = make_unique<node>();
		printnowallocusage();
	}
	printnowallocusage();

	delete n;
	printnowallocusage();
	cin.get();
}