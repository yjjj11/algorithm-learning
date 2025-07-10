#include<iostream>
#include<memory>
#include<chrono>
class Timer{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
public:
    Timer(){
        start=std::chrono::high_resolution_clock::now();
    }
~Timer() {
    end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;
    // 转换为毫秒并输出
    float ms = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    std::cout << "耗时: " << ms << " 毫秒" << std::endl;
}

};
void make(){
    Timer t;
    int a=0;
    for(int i=1;i<=10000000;i++){
        a+=2;
    }
    std::cout<<"end\n";
}
struct node{
    int x,y;
};
int main(){
    make();

    {   
        std::cout<<"shared1 make_shared\n";
        std::array<std::shared_ptr<node>,10000>  shared1;
        Timer t;
        for(int i=0;i<10000;i++){
            shared1[i]=std::make_shared<node>();
            //用makeshare构建新指针比new快，这是一个指针数组
        }
    }
    {
        std::cout<<"shared1 new\n";
        std::array<std::shared_ptr<node>,10000>  shared1;
        Timer t;
        for(int i=0;i<10000;i++){
            shared1[i]=std::shared_ptr<node>(new node());
           
        }
    }   
    {
        std::cout<<"shared1 make_unique\n";
        std::array<std::unique_ptr<node>,10000>  shared1;
        Timer t;
        for(int i=0;i<10000;i++){
            shared1[i]=std::make_unique<node>();
            //用makeshare构建新指针比new快，这是一个指针数组
        }
    }
    std::cin.get();
}
