#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    
    node(int x,int y):x(x),y(y){};//构造函数

    node operator+(const node &other)const{
        return node(x+other.x,y+other.y);
    }//重写加法运算符
    node add(const node &other)const{
        return node(x+other.x,y+other.y);
    }//自己写

    node operator*(const node &other)const{
        return node(x*other.x,y*other.y);
    }//重写乘法运算符
    
    node multipul(const node &other)const{
        return node(x*other.x,y*other.y);
    }//自己写

    bool operator==(const node &other)const{
        return x==other.x&&y==other.y;
    }

    bool operator==(const node &other)const{
        return !operator==(other);
        //return !(*this==other);
    }
};

ostream& operator<<(ostream& stream,const node& now){
    stream<<now.x<<" , "<<now.y<<"\n";
    return stream;
};//重载<<输出

int main(){
    node a(1,1);
    node b(5,5);
    node c(2,2);
    node now=a*c+b;//大大节省了类与类之间的操作；
    //否则应该是这样的
     now =b.add(a.multipul(c));

     cout <<now<<"\n";

}