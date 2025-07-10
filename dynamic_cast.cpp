#include<iostream>
#include<string>

class Entity{
public:
    virtual void print(){};
};
class Player:public Entity{
public:

};
class Enemy:public Entity{
public:

};
int main(){
    Player* player=new Player();
    Entity* e=player;
    Entity* e1=new Enemy();

    Player* p=dynamic_cast<Player*>(e);
    //如果不能转换就返回空指针，否则返回真是值
    //runtime type imformation增加了开销
    if(dynamic_cast<Player*>(e1)){
        //do something
    }
    //通过这种方法来测试是否可以转换
    
}