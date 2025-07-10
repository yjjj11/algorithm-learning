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

class scopenode
{
public:
    node* mynode;
    scopenode(node * newnode)
        :mynode(newnode){
            cout<<"create node now\n";
        };
    ~scopenode(){
        delete mynode;
        cout<<"destroyed node now \n";
    }

    
};
int main(){
    {
        node a;

    }//在栈上创建变量
    //create node now
    //destroyed node now 
    {
        node *a=new node();

    }//在堆上创建变量
    //create node now   堆上创建的变量在跳出作用域之后不会被示范


    //如果想要在堆上创建变量但是仍然希望超出作用域之后自动销毁？
    //第一种方法：写一个作用域类
    {
        scopenode mynode=new node();
        //在堆上创建大型变量并且可以在走出作用域之后自行销毁
    }
    //第二种方法:unique_ptr
    {
        unique_ptr<node> mynode=make_unique<node>();
        mynode->print();
        //create node now
        //Im here!
        //destroyed node now 
    }
}