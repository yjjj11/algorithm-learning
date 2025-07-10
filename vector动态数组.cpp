#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;

    node(int x,int y,int z):x(x),y(y),z(z){};

    node(const node& other):x(other.x),y(other.y),z(other.z){
        cout<<"copied!\n";
    };
};

ostream& operator<<(ostream& stream,const node & me){
    stream<<me.x<<","<<me.y<<","<<me.z<<"\n";
    return stream;
}

void function(const node& a){//记得要用引用输入，避免复制数组
    //print;
}

int main(){
    vector<node>a;
    // a.reserve(3);
//直接预先分配给a三个结构体空间，这样就不用再每次push时重新分配内存
    a.emplace_back(1,2,3);
    a.emplace_back(4,5,6);
    a.emplace_back(7,8,9);

    //emplace可以直接在vector分配的空间中创建对象
    //而不是先在main的栈上创建然后复制到vector的内存中去
    for(int i=0;i<a.size();i++){
        cout<<a[i];
    }

    for(node& j:a){
        cout<<j;
    }
    a.erase(a.begin()+1);
    cout<<"\n";
    for(node& j:a){
        cout<<j;
    }

}