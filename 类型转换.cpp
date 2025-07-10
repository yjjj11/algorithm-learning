#include<iostream>

class Base{
public:
    Base(){
        std::cout<<"Base Constructor\n";
    };
    virtual ~Base(){std::cout<<"Base Destructor\n";};
};
class Derived:public Base{
public:
    Derived(){std::cout<<"Derived Constructor\n";};
    ~Derived(){std::cout<<"Derived Destructor\n";};
};
class another:public Base{
public:
    another(){std::cout<<"Derived Constructor\n";};
    ~another(){std::cout<<"Derived Destructor\n";};
};
int main(){

    double value=5.2;
    double s=static_cast<int>(value)+5.3;
    
    Derived* d=new Derived();
    Base* base=d;
    another* ac=dynamic_cast<another*>(base);
    

    std::cin.get();

}