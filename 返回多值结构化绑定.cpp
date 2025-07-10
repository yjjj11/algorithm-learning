#include<iostream>
#include<tuple>
std::tuple<std::string,int>creatperson(){
    return {"cherno",24};
}
int main(){
    auto[name,age]=creatperson();
    std::cout<<name<<std::endl;
}