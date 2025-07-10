#include<bits/stdc++.h>
using namespace std;

template<typename T>//加上模板的函数只有在main中被调用时才会创建
void print(T a){
    cout<<a<<"\n";
}
// void print(string a){
//     cout<<a<<"\n";
// }
// void print(double a){
//     cout<<a<<"\n";
// }
template<typename T,int N>
class Array{
public:
    T array[N];
    int getsize()const{return N;}
};
int main(){
    print<int>(5);
    print<double>(5.5);
    print<string>("dwda");
    Array<string,10> array;
}