#include<iostream>
struct node{
    int x,y;
    int* getposition(){
        return &x;
    }
};
int main(){
    int a=50;
    double value=*(double*)&a;
    std::cout<<value<<std::endl;
    std::cin.get(); 

    node e;
    int *position=(int *)&e;
    // int *position=e.getposition();
    int y=e.y;
    y=*(int*)((char*)&e+4);
    std::cout<<y<<"\n";
    std::cout<<position[0]<<position[1]<<std::endl;
}