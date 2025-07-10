//智能指针都会在作用域结束之后自动释放
#include<bits/stdc++.h>
using namespace std;
#include<memory>
class node{
public:
    int a;
    node(){
        cout<<"create node now\n";
    }
    ~node(){
        cout<<"destroyed node now \n";
    }
    void print(){cout<<"Im here!\n";}
};

int main(){

    
    {
        unique_ptr<node> mynode=make_unique<node>();
        mynode->print();
        //node *e;
        //e=mynode;//会报错，因为unique_ptr不允许一块内存两个指针

    }//跳出作用域之后会释放

    {   
       shared_ptr<node> e;
       weak_ptr<node> e0;
       {
            shared_ptr<node> my=make_shared<node>();
            e=my;//共享指针会额外分配一块内存用于count计数
            //当count为0时释放
            e0=my;//虚指针不会增加count
        }
        
    }
    //共享指针只有在所有指向它的指针都被释放之后才会析构
}