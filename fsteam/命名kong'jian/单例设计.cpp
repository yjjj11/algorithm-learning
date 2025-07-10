#include<iostream>
#include<string>
using namespace std;

class node{
private:
    node(){};
    node(const node& other){};
    static node*n;
public:
    int a;
    static node* create(){return n;}
    void print(){
        cout<<"我是单例模式\n";
    }
};
node* node::n=new node();//初始化唯一单例
int main(){
    node* n=node::create();
    node* n1=node::create();
    cout<<n<<" "<<n1<<"\n";
    return 0;
}