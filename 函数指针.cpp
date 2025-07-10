#include<bits/stdc++.h>
using namespace std;
void hello(int a){
    cout<<"helloworld\n";
}
void print(int value){
    cout<<value<<" ";
}
void foreach(const vector<int>&a,const function<void(int)>& func){
    for(int as:a){
        func(as);
    }
}
int main(){
    auto func=hello;
    func(5);

    typedef void(*hellofunc)(int);
    hellofunc hi=hello;
    hi(6);
    //两种用法实际上是一样的
    //typedef void(*hellofunc)(int);
    //实际上定义了auto隐含的类型hellofunc

    vector<int>a={1,2,3,4,5};
    foreach(a,print);
    cout<<"\n";
    int b=2;
    foreach(a,[](int value){cout<<value<<" ";});
    //lamda函数
    foreach(a,[=](int value){cout<<b<<" ";});//值传递
    foreach(a,[&](int value){cout<<b<<" ";});//引用传递
    //甚至可以引用外部参数

    auto it=find_if(a.begin(),a.end(),[](int value){return value>3;});
    cout<<*it<<"\n";//一旦找到函数
}