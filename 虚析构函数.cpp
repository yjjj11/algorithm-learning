#include<iostream>

class Base{
public:
    Base(){
        std::cout<<"Base Constructor\n";
    };
    virtual ~Base(){std::cout<<"Base Destructor\n";};
};
class Derived:public Base{
private:
    int * m_array;;
public:
    Derived(){m_array=new int();std::cout<<"Derived Constructor\n";};
    ~Derived(){delete[] m_array;std::cout<<"Derived Destructor\n";};
};
int main(){

    Base*base=new Base();
    delete base;
    std::cout<<"-----------------\n";
    Derived* Deriveds=new Derived();
    delete(Deriveds);
    std::cout<<"-----------------\n";
    Base* poly=new Derived();
    delete(poly);//如果只调用基类析构函数而不调用派生类析构函数
    //可能会造成内存泄漏，内存泄露就是指明明是用不到了的空间却无法访问


    std::cin.get();

}