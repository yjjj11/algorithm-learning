#include<bits/stdc++.h>
using namespace std;


class printbale
{
public:
    virtual  void getClassName()=0;
};

class Entity: public printbale
{
public:
    virtual string Getname()=0;//=0将该函数设置为一个抽象函数
    //强迫子类在其类函数中重载一遍

    void getClassName() override{
        cout<<"Entity\n";
    }
};   

class Play: public Entity
{
private:
    string Name;
public:
    void setname(string name){
        Name=name;
    }
    string Getname() override {
        return Name;
    }
};
void printname(Entity & e){//不复制对象且会修改，传入的是实例
    cout<<e.Getname()<<"\n";
}

void printname1(Entity* e){//不复制对象会修改，传入的是指针
    cout<<e->Getname()<<"\n";
}

// void printname1(const Entity* e){//不复制对象不会修改，传入的是指针
//     cout<<e->Getname()<<"\n";
// }

void printname2(Play e){//复制对象且不会修改
    cout<<e.Getname()<<"\n";
}
int main(){
    // Entity *e=new Entity();//创造一个该类的指针
    // Entity e;//创建一个该类的实例对象
    //抽象类不允许定义实例
    Play p;
    p.setname("caty");
    cout<<p.Getname()<<"\n";
    printname(p);

    Play *p1=new Play();
    p1->setname("Petter");
    cout<<p1->Getname()<<"\n";
    printname1(p1);


    p.getClassName();
}