#include<bits/stdc++.h>
#include<cstddef>
using namespace std;
struct node{
    int a,b,c;

};
class mov{
private:
    int x;
public:
    mov():x(0){};
    void print(){cout<<"HELLO\n";}
};

class scopemov{
private:
    mov* movv;
public:
    scopemov(mov* now):movv(now){};//构造函数的传入不要加const
    ~scopemov(){
        delete movv;
    }
    mov* get(){return movv;}

    mov* operator->(){//重载箭头符
        return movv;
    }
};
int main(){
    //用箭头运算符获取各个变量的在类 或者结构体或者字节流中的偏移位置
    //int offset=(int)&((node*)nullptr)->a;
    size_t offset=offsetof(node,a);//和使用函数求偏移量一样

    cout<<offset<<"\n";

    scopemov mymov=new mov();
    //现在我要调用print函数打印出hello
    //1.不重载->时的打印方法
    mymov.get()->print();
    //2.重载后的打印方法
    mymov->print();


}