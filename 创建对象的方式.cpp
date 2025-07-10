#include<bits/stdc++.h>
using namespace std;

class Entity
{
private :
    string Name;
    int age;
public:
    explicit Entity(int Age) : Name("unknown"),age(Age){};
    //explict拒绝隐式转换
    Entity(const string& name): Name(name),age(-1){};
    Entity(): Name("unknown"),age(-1){;}

    const string getName() const{
        return Name;
    }
};
int main(){
    Entity e0;
    cout<<e0.getName()<<"\n";
    //尽量这样创建
    Entity e1("yjj");
    cout<<e0.getName()<<"\n";
    //创建实例对象，在栈上分布，但通常栈是非常小的，我们需要创建指针来在堆上分配内存

    Entity *e;
    {
        Entity entity("zyt");
        e=&entity;
        cout<<e->getName()<<"\n";
    }//这个entity在出了括号之后就会被覆盖，而且e的指向hi发生改变

    {//在堆上分配内存，需要手动释放内存
        Entity *entity=new Entity("zyt");
        e=entity;//两个变量指向的是同一个内存地址
        cout<<e->getName()<<"\n";
        delete entity;
    }//这个entity在出了括号之后就会被覆盖，而且e的指向hi发生改变
    delete e;


    int a=2;
    int *b=new int[50];
    int *c=new int;
    Entity *e=new Entity("zyt");//调用了构造函数
    Entity *e1=new Entity[50];//没有调用构造函数
    delete e,e1;
    delete[] b;
    //new和delete都是操作符,一个new对应一个delete


    Entity c("Cherno");
    Entity b=22;
}