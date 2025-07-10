#include<iostream>
using namespace std;

void print(string& name){cout<<"lvalue "<<name<<"\n";}
//这种叫做左值引用，只接受左值
void print(const string& name){cout<<name<<"\n";}
//加上const就两个都可以接受
void print(string&& name){cout<<"rvalue "<<name<<"\n";}
//只接受右值
int main(){
    string firstname="y";
    string secondname="jj";
    string fullname=firstname+secondname;


    //临时变量或者没有实际存储地址的都叫做右值
    print(fullname);
    print(firstname+secondname);//优先选择自己的函数而非公立函数
}