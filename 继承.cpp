#include<bits/stdc++.h>
using namespace std;

class Entity//具体类
{
public:
    enum local{
        a,b,c
    };

    local C;//使用枚举限定变量取值范围
    local D;
    int X,Y;
    Entity(){//构造函数
        X=a;
        Y=b;
        cout<<"already created\n";
    }
    void move(int dx,int dy){
        X+=dx;
        Y+=dy;
    }
    void printlocal(){
        cout<<X<<" "<<Y<<"\n";
    }

    ~Entity(){
        cout<<"already destroyed\n";
    }
};

class Player :public Entity
{
public: 
    const char * name;

    void printName(){cout<<name<<"\n";}


};
int main(){
    cout<<sizeof(Entity)<<"\n";
    cout<<sizeof(Player)<<"\n";

    Player p1;
    p1.X=5;
    p1.printlocal();
    p1.move(5,5);
    p1.printlocal();
}