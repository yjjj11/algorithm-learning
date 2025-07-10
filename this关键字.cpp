#include<bits/stdc++.h>
using namespace std;
class node;
void printnode(const node& now);

class node
{
public:
    int x,y;
    node(int x,int y){
        this->x=x;
        this->y=y;

        printnode(*this);
    }//第一种方法用在构造函数中

    int getnode(){
        return this->x;
    }


};
void printnode(const node& now){
    //print;
    cout<<now.x<<"  "<<now.y<<"\n";
}
int main(){
    node a(1,1);
    cout<<a.getnode();
}