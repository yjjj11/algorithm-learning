#include<iostream>
#include<fstream>
#include <filesystem> // C++17及以上，用于获取当前工作目录
using namespace std;
namespace A
{
    int b=10,c=1;
    namespace AA
    {
        int b=100;
    }
    namespace BB
    {
        int b=39;
    }
}
namespace{
    int a=0;
}//匿名的命名空间实际就是全局的：：;
namespace C=A;
int main() {
    int a=10;
    cout<<a<<"\n";
    cout<<::a<<"\n";
    cout<<&a<<"\n"<<&(::a)<<"\n";

    cout<<A::b<<"\n";
    using A::b;
    cout<<b<<"\n";
    using namespace A;
    cout<<c<<"\n";

    cout<<A::AA::b<<"\n";
    cout<<A::BB::b<<"\n";
    cout<<"取别名\n";
    cout<<C::AA::b<<"\n";
    cout<<C::BB::b<<"\n";
    return 0;
}